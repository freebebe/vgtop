if has("nvim")
    let g:plug_home = stdpath('data') . './.plugged'
endif

call plug#begin('$HOME/.config/nvim/.plugged')

" Plug 'tpope/vim-fugitive'
" Plug 'tpope/vim-rhubarb'
" Plug 'abecodes/tabout.nvim'
Plug 'tomtom/tcomment_vim'

if has ("nvim")
    Plug 'hoob3rt/lualine.nvim'

    Plug 'Shougo/defx.nvim', { 'do': ':UpdateRemotePlugins' }
    Plug 'kristijanhusak/defx-git'

    Plug 'neovim/nvim-lspconfig'
    Plug 'glepnir/lspsaga.nvim'

    Plug 'hrsh7th/nvim-cmp'
    Plug 'hrsh7th/cmp-nvim-lsp'
    Plug 'hrsh7th/cmp-buffer'

    Plug 'L3MON4D3/LuaSnip'
    Plug 'saadparwaiz1/cmp_luasnip'

    Plug 'nvim-lua/popup.nvim'
    Plug 'nvim-lua/plenary.nvim'
    Plug 'nvim-telescope/telescope.nvim'

    " Plug 'Yggdroot/indentLine'

    Plug 'kyazdani42/nvim-web-devicons'
    " Plug 'blackCauldron7/surround.nvim'

    " Plug 'lewis6991/gitsigns.nvim'
    Plug 'mg979/vim-visual-multi', {'branch': 'master'}
    " Plug 'windwp/nvim-autopairs'
    "{} () <>

    Plug 'jose-elias-alvarez/null-ls.nvim'
endif

Plug 'mattn/emmet-vim'
Plug 'norcalli/nvim-colorizer.lua'

" Plug 'kchmck/vim-coffee-script'

call plug#end()
