# useful-compilation-commansd



`compile(){cc "$1" -Wextra -Wall -Werror "$2" && echo  "Compiled $1 successfully" || echo "Compilation issues: $1"; norminette "$1" -R CheckForbiddenSourceHeader;}`
