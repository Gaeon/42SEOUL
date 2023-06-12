| Program name
프로그램 이름 | libft.a |
| --- | --- |
| Turn in files
제출할 파일 | Makefile, libft.h, ft_*.c |
| Makefile | Name, all, clean, fclean, re |
| External functs.
사용가능한외부 함수 | Detailed below
자세한 내용은 아래를 확인하세요 |
| Libft authorized | n/a |
| Description
설명 | Write your own library: a collection of functions that will be a useful too for your cursus.
42 과정을 진행하면서 유용하게 쓰일 수 있는 함수들을 담은, 여러분만의 라이브러리를 작성하세요 |

## Technical considerations

- **It is forbidden to declare global variables.**
    
    전역변수는 사용할 수 없습니다.
    
- **If you need subfunctions to write a complex function, you should define these subfunctions as `static` to avoid publishing them with your library. It would be a good habit to do this in your future projects as well.**
    
    복잡한 함수를 구현하기 위해 하위 함수 (subfunction) 을 작성해야 한다면, 이러한 함수들을 `static` 으로 선언하여 라이브러리와 함께 컴파일되는 것을 막는 것이 좋습니다. 이러한 습관은 나중의 프로젝트를 진행할 때도 도움이 될 거에요.
    
- **Submit all files in the root of your repository.**
    
    모든 파일을 레포지토리의 루트 폴더에 제출하세요.
    
- **It is forbidden to submit unused files.**
    
    사용하지 않는 파일의 제출은 금지됩니다.
    
- **Every .c must compile with flags.**
    
    모든 .c 파일은 플래그와 함께 컴파일되어야 합니다.
    
- **You must use the command `ar` to create your library, using the command `libtool` is forbidden.**
    
    반드시 `ar` 명령어를 사용하여 라이브러리를 생성하여야 합니다. `libtool` 명령어는 사용이 금지됩니다.
    

## Part 1 - Libc functions

**In this first part, you must re-code a set of the `libc` functions, as defined in their `man`. Your functions will need to present the same prototype and behaviors as the originals. Your functions’ names must be prefixed by "`ft_`". For instance, `strlen`becomes`ft_strlen`.**

첫 번째 파트에서는, `man`에 정의되어 있는 그대로 `libc` 함수들을 새로 구현하셔야 합니다. 여러분의 함수들은 원본과 같은 프로토타입으로 선언되어야 하며, 같은 방식으로 동작해야 합니다. 다만 함수의 이름 앞에는 `"ft_"`를 붙여야 합니다. 예를 들면, `strlen`을 구현한 함수의 이름은 `ft_strlen`이 됩니다.

> 💡 **Some of the functions’ prototypes you have to re-code use the "restrict" qualifier. This keyword is part of the c99 standard. It is therefore forbidden to include it in your prototypes and to compile it with the flag `std=c99`.**
> 
> 
> 여러분이 재구현하여야 하는 함수들 중 일부는 원본의 프로토타입에 "restrict" 한정자가 사용됩니다. 이 키워드는 c99 표준에 해당하므로, 여러분의 라이브러리 프로토타입들에 이 키워드를 포함시키고 `std=c99` 플래그를 사용하여 컴파일하는 것은 금지됩니다.
> 

**You must re-code the following functions. These function do not need any external functions:**

아래의 함수들을 다시 구현하세요. 이 함수들은 외부 함수를 필요로 하지 않습니다 :

- `isalpha`, `isdigit`, `isalnum`, `isascii`, `isprint`
- `strlen`, `memset`, `bzero`, `memcpy`, `memmove`, `strlcpy`, `strlcat`, `strncmp`
- `toupper`, `tolower`, `strchr`, `strrchr`
- `memchr`, `memcmp`, `strnstr`, `atoi`

**You must also re-code the following functions, using the function "`malloc`":**

다음의 함수들은 외부 함수 `malloc` 을 사용하여 구현하세요 :

- `calloc`, `strdup`

## Part 2 - Additional functions

**In this second part, you must code a set of functions that are either not included in the `libc`, or included in a different form.** 

두 번째 파트에서는, `libc`에 포함되어 있지 않거나 다른 형식으로 포함된 함수들을 재구현하여야 합니다. 

> 💡**Some of these functions can be useful to write Part 1’s functions.**
다음 함수들 중 일부는 Part 1 함수를 작성할 때 도움이 될 거에요.
> 

| Function name
함수 이름 | ft_substr |
| --- | --- |
| Prototype
프로토타입 | char *ft_substr(char const *s, unsigned int start, size_t len); |
| Turn in files
제출할 파일 | - |
| Parameters
매개변수 | s: The string from which to create the substring.
start: The start index of the substring in the string ’s’.
len: The maximum length of the substring.
s: 부분 문자열 (substring) 을 생성할 원본 문자열
start: 부분 문자열의 맨 처음 인덱스
len: 부분 문자열의 최대 길이 |
| Return Value
반환값 | The substring. NULL if the allocation fails.
부분 문자열. 할당 실패 시, NULL |
| External functs.
사용가능한외부 함수 | malloc |
| Description
설명 | Allocates (with malloc(3)) and returns a substring from the string ’s’. The substring begins at index ’start’ and is of maximum size ’len’.
malloc(3) 을 이용하여 메모리를 할당받은 후, 원본 문자열 's' 로부터 부분 문자열을 생성하여 반환합니다.부분 문자열은 인덱스 'start' 부터 시작하며, 최대 길이 'len'을 갖습니다. |

| Function name
함수 이름 | ft_strjoin |
| --- | --- |
| Prototype
프로토타입 | char *ft_strjoin(char const *s1, char const *s2); |
| Turn in files
제출할 파일 | - |
| Parameters
매개변수 | s1: The prefix string.
s2: The suffix string.
s1: 접두 문자열
 s2: 접미 문자열 |
| Return Value
반환값 | The new string. NULL if the allocation fails.
새로운 문자열. 할당 실패 시, NULL |
| External functs.
사용가능한외부 함수 | malloc |
| Description
설명 | Allocates (with malloc(3)) and returns a new string, which is the result of the concatenation of ’s1’ and ’s2’.
malloc(3) 을 이용하여 메모리를 할당받은 후, 문자열 's1' 과 's2' 를 이어붙인 새로운 문자열을 생성하여 반환합니다. |

| Function name
함수 이름 | ft_strtrim |
| --- | --- |
| Prototype
프로토타입 | char *ft_strtrim(char const *s1, char const *set); |
| Turn in files
제출할 파일 | - |
| Parameters
매개변수 | s1: The string to be trimmed.
set: The reference set of characters to trim.
s1: 양 쪽을 잘라낼 원본 문자열
 set: 제거될 문자들의 집합 |
| Return Value
반환값 | The trimmed string. NULL if the allocation fails.
문자가 제거된 문자열. 할당 실패 시, NULL |
| External functs.
사용가능한외부 함수 | malloc |
| Description
설명 | Allocates (with malloc(3)) and returns a copy of ’s1’ with the characters specified in ’set’ removed from the beginning and the end of the string.
malloc(3) 을 이용하여 메모리를 할당받은 후, 's1'의 양 쪽 끝에서 'set'에 지정된 문자들이 제거된 문자열 사본을 반환합니다. |

| Function name
함수 이름 | ft_split |
| --- | --- |
| Prototype
프로토타입 | char **ft_split(char const *s, char c); |
| Turn in files
제출할 파일 | - |
| Parameters
매개변수 | s: The string to be split.
c: The delimiter character.
s: 분할할 문자열
 c: 구분자 |
| Return Value
반환값 | The array of new strings resulting from the split. NULL if the allocation fails.
split을 통해 분할된 문자열의 배열. 할당 실패 시, NULL |
| External functs.
사용가능한외부 함수 | malloc, free |
| Description
설명 | Allocates (with malloc(3)) and returns an array of strings obtained by splitting ’s’ using the character ’c’ as a delimiter. The array must be ended by a NULL pointer.
malloc(3) 을 이용하여 메모리를 할당받은 후, 구분자 'c' 를 기준으로 문자열 's'를 분할하여 그 결과를 담은 새로운 문자열 배열을 반환합니다. 문자열 배열의 끝은 NULL 포인터로 끝나야 합니다. |

| Function name
함수 이름 | ft_itoa |
| --- | --- |
| Prototype
프로토타입 | char *ft_itoa(int n); |
| Turn in files
제출할 파일 | - |
| Parameters
매개변수 | n: the integer to convert.
n: 변환할 정수 |
| Return Value
반환값 | The string representing the integer. NULL if the allocation fails.
정수를 표현하는 문자열. 할당 실패 시, NULL |
| External functs.
사용가능한외부 함수 | malloc |
| Description
설명 | Allocates (with malloc(3)) and returns a string representing the integer received as an argument. Negative numbers must be handled.
malloc(3) 을 이용하여 메모리를 할당받은 후, 인자로 받은 정수를 나타내는 문자열을 반환합니다. 음수 또한 무조건 처리되어야 합니다. |

| Function name
함수 이름 | ft_strmapi |
| --- | --- |
| Prototype
프로토타입 | char *ft_strmapi(char const *s, char (*f)(unsigned int, char)); |
| Turn in files
제출할 파일 | - |
| Parameters
매개변수 | s: The string on which to iterate.
f: The function to apply to each character.
s: 함수를 적용할 문자열
f: 문자열의 각 문자에 적용할 함수 |
| Return Value
반환값 | The string created from the successive applications
of ’f’. Returns NULL if the allocation fails.
원본 문자열에서 함수 'f'를 성공적으로 적용하여 생성된 결과 문자열. 할당 실패 시, NULL |
| External functs.
사용가능한외부 함수 | malloc |
| Description
설명 | Applies the function ’f’ to each character of the string ’s’ , and passing its index as first argument to create a new string (with malloc(3)) resulting from successive applications of ’f’.
문자열 's' 의 각 문자를 순회하며 함수 'f'를 적용하고, 해당 문자의 인덱스를 함수 'f'의 첫 번째 인자로 사용합니다. 각 문자에 함수가 적용된 새로운 문자열을 생성합니다 (malloc(3) 을 이용하여 메모리를 할당) |

| Function name
함수 이름 | ft_striteri |
| --- | --- |
| Prototype
프로토타입 | void ft_striteri(char *s, void (*f)(unsigned int, char*)); |
| Turn in files
제출할 파일 | - |
| Parameters
매개변수 | s: The string on which to iterate.
f: The function to apply to each character.
s: 함수를 적용할 문자열
f: 문자열의 각 문자에 적용할 함수 |
| Return Value
반환값 | None
없음 |
| External functs.
사용가능한외부 함수 | None
없음 |
| Description
설명 | Applies the function f to each character of the string passed as argument, and passing its index as first argument. Each character is passed by address to f to be modified if necessary.
문자열 's' 의 각 문자를 순회하며 함수 'f'를 적용하고, 해당 문자의 인덱스를 함수 'f'의 첫 번째 인자로 사용합니다. 또한 각 문자의 주소값이 'f' 함수의 두 번째 인자로 사용되며, 경우에 따라 수정될 수 있습니다. |

| Function name
함수 이름 | ft_putchar_fd |
| --- | --- |
| Prototype
프로토타입 | void ft_putchar_fd(char c, int fd); |
| Turn in files
제출할 파일 | - |
| Parameters
매개변수 | c: The character to output.
fd: The file descriptor on which to write
c: 출력할 문자
 fd: 값이 쓰여질 파일 식별자 (file descriptor) |
| Return Value
반환값 | None
없음 |
| External functs.
사용가능한외부 함수 | write |
| Description
설명 | Outputs the character ’c’ to the given file descriptor.
제공받은 파일 식별자에 문자 'c'를 출력합니다. |

| Function name
함수 이름 | ft_putstr_fd |
| --- | --- |
| Prototype
프로토타입 | void ft_putstr_fd(char *s, int fd); |
| Turn in files
제출할 파일 | - |
| Parameters
매개변수 | s: The string to output.
fd: The file descriptor on which to write.
s: 출력할 문자열 
 fd: 값이 쓰여질 파일 식별자 (file descriptor) |
| Return Value
반환값 | None
없음 |
| External functs.
사용가능한외부 함수 | write |
| Description
설명 | Outputs the string ’s’ to the given file descriptor.
제공받은 파일 식별자에 문자열 's'를 출력합니다. |

| Function name
함수 이름 | ft_putendl_fd |
| --- | --- |
| Prototype
프로토타입 | void ft_putendl_fd(char *s, int fd); |
| Turn in files
제출할 파일 | - |
| Parameters
매개변수 | s: The string to output.
fd: The file descriptor on which to write.
s: 출력할 문자열
 fd: 값이 쓰여질 파일 식별자 (file descriptor) |
| Return Value
반환값 | None
없음 |
| External functs.
사용가능한외부 함수 | write |
| Description
설명 | Outputs the string ’s’ to the given file descriptor, followed by a newline.
제공받은 파일 식별자에 문자열 's'를 출력하고, 개행을 출력합니다. |

| Function name
함수 이름 | ft_putnbr_fd |
| --- | --- |
| Prototype
프로토타입 | void ft_putnbr_fd(int n, int fd); |
| Turn in files
제출할 파일 | - |
| Parameters
매개변수 | n: The integer to output.
fd: The file descriptor on which to write.
n: 출력할 정수
 fd: 값이 쓰여질 파일 식별자 (file descriptor) |
| Return Value
반환값 | None
없음 |
| External functs.
사용가능한외부 함수 | write |
| Description
설명 | Outputs the integer ’n’ to the given file descriptor.
제공받은 파일 식별자에 정수 'n'를 출력합니다. |