#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;

class StrBlobPtr;
class StrBlob
{
public:
    friend class StrBlobPtr;
	typedef vector<string>::size_type size_type;
	StrBlob();
	StrBlob(initializer_list<string> il);
	size_type size() const { return data->size();}
	bool empty() const { return data->empty(); }
	// 添加和删除元素
	void push_back(const string &t) { data->push_back(t);}
	void pop_back();
	// 元素访问
	string & front();
	string & back();
    StrBlobPtr begin();
    StrBlobPtr end();
private:
	shared_ptr< vector<string> > data;
	// 如果data[i]不合法,抛出一个异常
	void check(size_type i, const string &msg) const;

};

StrBlob::StrBlob(): data(make_shared< vector<string> >()) {}

StrBlob::StrBlob(initializer_list<string> il): data(make_shared< vector<string> >(il)){}

void StrBlob::check(size_type i, const string &msg) const
{
    if (i >= data->size())
	throw out_of_range(msg);
}

void StrBlob::pop_back()
{
    check(0, "pop_back on empty StrBlob");
    data->pop_back();
}

string & StrBlob::front()
{
    check(0, "front on empty StrBlob");
    return data->front();
}

string & StrBlob::back()
{
    check(0, "back on empty StrBlob");
    return data->back();
}

class StrBlobPtr
{
public:
    StrBlobPtr(): curr(0) {}
    StrBlobPtr(StrBlob &a, size_t sz = 0): wptr(a.data), curr(sz) {}
    string &deref() const;
    StrBlobPtr &incr();
private:
    shared_ptr< vector<string> > check(size_t, const string &) const;
    weak_ptr< vector<string> > wptr;
    size_t curr;
};

shared_ptr< vector<string> > StrBlobPtr::check(size_t i, const string &msg) const
{
    auto ret = wptr.lock();
    if (!ret)
        throw runtime_error("unbound StrBlobPtr");
    if (i >= ret->size())
        throw out_of_range(msg);
    return ret;
}

string &StrBlobPtr::deref() const
{
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
}

StrBlobPtr &StrBlobPtr::incr()
{
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}
StrBlobPtr StrBlob::begin()
{ 
    return StrBlobPtr(*this); 
}
StrBlobPtr StrBlob::end()
{
    auto ret = StrBlobPtr(*this, data->size()); return ret;
}
