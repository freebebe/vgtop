if exists("&termguicolors") && exists("&winblend")
    " au ColorScheme * hi Normal ctermbg=none guibg=none
    " au ColorScheme myspecialcolors hi Normal ctermbg=red guibg=red

lua << EOF
EOF

   set winblend=0
   set wildoptions=pum
   set pumblend=5
   " set background=dark
   " colo vscode
   " colo vscodeL
   colo whiteBlue

endif

