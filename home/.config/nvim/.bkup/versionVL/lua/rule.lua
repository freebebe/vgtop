--Set leader to space key
vim.g.mapleader = ' '

--Set highlight on search
vim.o.hlsearch = false

--Save undo history
vim.opt.undofile = true

--Case insensitive searching UNLESS /C or capital in search
vim.o.ignorecase = true
vim.o.smartcase = true

--Set colorscheme (order is important here)
vim.o.termguicolors = true

vim.api.nvim_exec([[
set list listchars=nbsp:¬,tab:»·,trail:·,extends:>
set shiftwidth=4
set softtabstop=4
set tabstop=4
set wildmode=longest,list,full
set wildmenu
]], true)
