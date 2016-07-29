#include <fstream>
#include <sstream>
#include <map>
#include <string>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

using namespace std;

int main(int argc, char **argv)
{
    ifstream in(argv[1]);
    if (!in.is_open())
        printf("open error\n");

    map<uint64_t, uint64_t> stack;

    char line[1024] = {0};
	int i = 0;
    while (!in.getline(line, 1024).eof())
    {
        string s = line;
        string key = s.substr(0, s.find(" "));
        string value = s.substr(s.find(" ") + 1);

        uint64_t int_key = 0;
        uint64_t int_value = 0;

        stringstream ss;
        ss << hex << key;
        ss >> int_key;
        ss.clear();
        ss << hex << value;
        ss >> int_value;

        stack.insert(make_pair(int_key, int_value));
        memset(line, 0, 1024);
    }

    map<uint64_t, uint64_t>::iterator it = stack.begin();
	i = 0;
    for (; it != stack.end(); ++it)
    {
        uint64_t key = it->second;
        int deepth = 0;
        while(stack.find(key) != stack.end())
        {
    		if (stack[key] > key)
    		{
    		    key = stack[key];
    		    deepth++;
    		}
    		else
    		{
    			break;
    		}
        }
        
        if (deepth >= atoi(argv[2]))
        {
            key = it->first;
            while(stack.find(key) != stack.end())
            {
                if(stack.find(key + sizeof(void*)) != stack.end())
                {
                    printf("info symbol 0x%llx\n", stack[key + sizeof(void *)]);
                }
                key =stack[key];
            }
            printf("\n");
        }
    }
	in.close();
	return 0;
}
