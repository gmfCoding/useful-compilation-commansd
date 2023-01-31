# useful-compilation-commansd


compile and run norminette
```
compile(){cc "$1" -Wextra -Wall -Werror "$2" && echo  "Compiled $1 successfully" || echo "Compilation issues: $1"; norminette "$1" -R CheckForbiddenSourceHeader;};
compile_a(){compile $1 $2 && ./a.out};
remove_uncom(){sed -i '' -e '/$DELETE/d' $1};
cc_uncom(){remove_uncom $1 && compile $1 $2};
cc_uncom_a(){cc_uncom $1 $2; ./a.out};
```
usage
`compile *.c`
This runs both compilation and norminette at once

`compile_a *.c`
This runs both compilation and norminette at once and then runs the a.out automatically

The uncom (ment) variant is used for automatically uncommenting main.
```
/* $DELETE
#include <stdio.h>
$DELETE */

void ft_exercise(void)
{
  ... exercise code
}

/* $DELETE
int main(void)
{
  ft_exercise();
  printf();
}
$DELETE */
```

Explanation:
The `remove_uncom` user defined shell function/command removes all lines that have $DELETE, so if you place this on the lines where you have the begin/end comment characters than when we use `cc_uncom <file_name>` it will remove those lines, then cc/gcc/clang will now read those files and those comments will be gone.
