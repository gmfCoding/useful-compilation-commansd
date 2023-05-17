# useful-compilation-commansd

Automation of 42 exercise compilation.

Auto un-comment and auto compile/run:
Comment out your main function like:

```c
/* DELETE_ME42
#include <stdio.h>
// The headers your exercise functions use should not be contained here, move them out.
DELETE_ME42 */

/* DELETE_ME42
void main(void)
{
  // Testing code
}
DELETE_ME42 */
```

To automatically remove these lines for a given file you can use:

`sed -i '' '/DELETE_ME42/d' example.c`

`-i` signifies apply to file, MACOS/BSD requires the double single quotes, this will overwrite your file, BE CAREFUL, make sure you are fully git added & commited first.

The second argument says delete the line if it contains 'DELETE_ME42', this is the one that removes those lines.
example.c is the file.


If you wanted to apply this to all exercises at once in one command use

`find ex**/*.c -type f -exec sed -i '' '/DELETE_ME42/d' {} \;`
This will run the sed command for each found .c file in each of the exercise directories.

You can then compile your exerecises with:

`find ex**/*.c -type f -exec cc -Werror -Wall -Wextra {} -o {}.o \;`

Then you can auto run each exercise with:

`find ex**/*.o -type f -exec {} && pwd \;`


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

View declared user defined functions/commands with `declare -f`

Codescan searches all your code for a phrase

```
codescan() {find . -type f -name "*.[hc]" -exec grep -I -H -n $1 {} \;}
```

Explanation:
uses find to search for files that end with 'h' or 'c' extensions, then runs grep on each of those files
`-I` means don't look in binary files
`-H` means output file name with
`-n` means output the line number
`$1` is the arg from calling codescan, it is the phrase
`{}` is the file name that find command subsitutes
`\;` is the end of the command
