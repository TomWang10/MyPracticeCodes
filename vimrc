set autoindent
set shiftwidth=4
set autoindent
set cursorline
set number
set expandtab
set tabstop=4
set t_Co=256

set nocompatible              " be iMproved, required
filetype off                  " required

"set the runtime path to include Vundle and initialize
set rtp+=~/.vim/bundle/Vundle.vim
call vundle#begin()
" alternatively, pass a path where Vundle should install plugins
"call vundle#begin('~/some/path/here')

" let Vundle manage Vundle, required
Plugin 'gmarik/Vundle.vim'

" The following are examples of different formats supported.
" Keep Plugin commands between vundle#begin/end.
" plugin on GitHub repo
"
Plugin 'Valloric/YouCompleteMe'
Plugin 'Mizuchi/STL-Syntax'
Plugin 'vim-scripts/a.vim'
Plugin 'kien/ctrlp.vim'

" All of your Plugins must be added before the following line
call vundle#end()            " required
filetype plugin indent on    " required
