| Function Name
함수 이름 | get_next_line |
| --- | --- |
| Prototype
프로토타입 | char *get_next_line(int fd); |
| Turn in files
제출할 파일 | get_next_line.c, get_next_line_utils.c, get_next_line.h |
| Parameter
매개변수 | fd: The file descriptor to read from
읽어들일 파일의 디스크립터 (서술자) |
| Return Value
반환값 | Read line: correct behavior
NULL: there is nothing else to read, or an error occurred
읽혀진 라인 : 한 줄이 제대로 읽힘NULL : 읽을 라인이 더이상 없거나 에러 발생 |
| External functs.
사용가능한외부 함수 | read, malloc, free |
| Description
설명 | Write a function that returns a line read from a file descriptor
파일 디스크립터로부터 한 줄을 읽고,반환하는 함수를 작성하시오. |
- **Calling your function `get_next_line` in a loop will then allow you to read the text available on the file descriptor one line at a time until the end of it.**
`get_next_line` 함수를 반복문 안에서 호출하면, 파일 디스크립터에 존재하는 텍스트를 EOF 전까지 한 번에 한 줄씩 읽어들일 수 있습니다.
- **Your function should return the line that has just been read. If there is nothing else to read or if an error has occurred it should return NULL.**
여러분의 함수는 방금 읽어들인 문자열 한 줄을 반환하여야 합니다. 더이상 읽어올 것이 없거나 에러가 발생하면 NULL을 반환하여야 합니다.
- **Make sure that your function behaves well when it reads from a file and when it reads from the standard input.**
파일에서 읽을 때, 표준입력으로부터 읽어들일 때 모두 함수가 제대로 동작하는지 확인하십시오.
- `**libft` is not allowed for this project. You must add a `get_next_line_utils.c` file which will contain the functions that are needed for your `get_next_line` to work.**
`libft`는 이 프로젝트에서 사용할 수 없습니다. 대신 `get_next_line_utils.c` 파일에 과제를 수행하는 데 필요한 함수들을 정의해야 합니다.
- **Your program must compile with the flag `D BUFFER_SIZE=xx` which will be used as the buffer size for the read calls in your `get_next_line`. This value will be modified by your evaluators and by the moulinette.**
당신의 프로그램은 `-D BUFFER_SIZE=xx` 플래그를 이용하여 컴파일 되어야 합니다. 이것은 여러분의 `get_next_line`에서 read함수를 호출하기 위한 buffer size로 사용될 것이며, Moulinette와 평가자가 임의로 값을 수정하여 테스트할 것입니다.
- **The program will be compiled in this way: `gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>.c`.**
컴파일은 이런 식으로 진행됩니다 :`gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <파일들>.c`
- **Your read must use the `BUFFER_SIZE` defined during compilation to read from a file or from stdin. This value will be modified during the evaluation for testing purposes.**
`read` 함수를 사용할 때에는, 파일 또는 표준 입력으로부터 값을 읽어들이기 위해 컴파일 시에 정의되는 `BUFFER_SIZE`를 사용해야 합니다. 평가 시에, 함수 테스트를 위하여 값이 변동될 수 있습니다.
- **In the header file `get_next_line.h` you must have at least the prototype of the function `get_next_line`.**
`get_next_line.h` (헤더 파일)에는 적어도 `get_next_line` 함수의 프로토타입이 존재하여야 합니다.

> 💡 **Does your function still work if the BUFFER_SIZE value is 9999? And if the BUFFER_SIZE value is 1? And 10000000? Do you know why?**
BUFFER_SIZE 값이 9999인 경우에도 함수는 여전히 작동하나요? BUFFER_SIZE 값이 1이라면? 10000000이라면? 왜 그런지 아시나요?
> 

> 💡 **You should try to read as little as possible each time get_next_line is called. If you encounter a newline, you have to return the current line. Don’t read the whole file and then process each line.**
get_next_line이 호출될 때마다 가능한 한 적게 읽어들이도록 해야 합니다. 만약 newline을 만나면, 현재 라인을 반환해야 합니다. 전체 파일을 읽어들인 다음에 한줄씩 처리하려 하지 마세요.
> 

> 💡 **Don’t turn in your project without testing. There are many tests to run, cover your bases. Try to read from a file, from a redirection, from standard input. How does your program behave when you send a newline to the standard output? And CTRL-D?**
테스트하지 않고 프로젝트를 제출하지 마세요. 여러분의 함수를 위해 돌려볼 수 있는 테스트는 많습니다. 파일로부터, redirection으로부터, stdin으로부터의 읽기를 시도해 보세요. 표준 출력에 newline을 보낼 때 프로그램은 어떻게 동작하나요? CTRL-D는요?
> 
- **lseek is not an allowed function. File reading must be done only once.**
`lseek`은 허용된 함수가 아닙니다. 파일 읽기는 오로지 한번만 행해져야 합니다.
- **We consider that `get_next_line` has undefined behavior if, between two calls, the same file descriptor switches to a different file before reading everything from the first fd.**
만약 동일한 파일 디스크립터의 두 호출 사이에서, 첫 번째 fd에서 EOF에 도달하기 전에 다른 파일로 전환될 경우, 우리는 `get_next_line`이 정의되지 않은 동작을 가진다고 생각합니다.
- **Finally we consider that `get_next_line` has undefined behavior when reading from a binary file. However, if you wish, you can make this behavior coherent.**
마지막으로 `get_next_line`은 바이너리 파일을 읽을 때 정의되지 않은 동작을 가진다고 생각하셔야 합니다. 그러나 여러분이 원한다면 이러한 동작을 논리적으로 구현하셔도 됩니다.
- **Global variables are forbidden.**
전역 변수는 금지되어 있습니다.
- **Important: The returned line should include the ’\n’, except if you have reached the end of file and there is no ’\n’..**
중요: 'eof에 도달하였고 `\n`이 존재하지 않을 때'를 제외하고, 함수가 반환하는 문자열 한 줄에는 `\n`이 포함되어야 합니다.

> ℹ️ **A good start would be to know what a static variable is:**
정적 변수가 무엇인지 익혀 두면 좋은 시작이 될 겁니다 :https://en.wikipedia.org/wiki/Static_variable
>