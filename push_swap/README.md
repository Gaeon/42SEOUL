## The rules

- **You have 2 stacks named a and b.**
게임은 두 개의 스택 a와 b를 가지고 진행됩니다.
- **At the beginning:**
시작 시점에서:
    - **The stack a contains a random amount of negative and/or positive numbers which cannot be duplicated.**
    스택 a는 랜덤한 개수의 양의 정수들과 음의정수들을 포함하며, 값은 중복되지 않습니다.
    - **The stack b is empty**
    스택 b는 비어있습니다.
- **The goal is to sort in ascending order numbers into stack a. To do this you have the following operations at your disposal:**
게임의 목표는 스택 a에 정수들을 오름차순으로 정렬하는 것입니다.여러분은 목표를 달성하기 위해서 다음과 같은 명령어를 사용하실 수 있어요:
    
    **sa : `swap a` - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.**
    sa : `swap a` - 스택 a의 top에 위치한 두 개의 원소의 순서를 맞바꿉니다. 스택 a가 비어있거나 원소가 1개만 있을 때는 아무 동작도 하지 않습니다.
    
    **sb : `swap b` - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements.**
    sb : `swap b` - 스택 b의 top에 위치한 두 개의 원소의 순서를 맞바꿉니다. 스택 b가 비어있거나 원소가 1개만 있을 때는 아무 동작도 하지 않습니다.
    
    **ss : `sa` and `sb` at the same time.**
    ss - `sa`와 `sb`를 동시에 수행합니다.
    
    **pa : `push a` - take the first element at the top of b and put it at the top of a. Do nothing if b is empty.**
    pa : `push a` - 스택 b의 top에 위치한 원소 한 개를 스택 a의 top으로 옮깁니다. 스택 b가 비어있을 경우에는 아무 동작도 하지 않습니다.
    
    **pb : `push b` take the first element at the top of a and put it at the top of b. Do nothing if a is empty.**
    pb : `push b` - 스택 a의 top에 위치한 원소 한 개를 스택 b의 top으로 옮깁니다. 스택 a가 비어있을 경우에는 아무 동작도 하지 않습니다.
    
    **ra : `rotate a` - shift up all elements of stack a by 1. The first element becomes the last one.**
    ra : `rotate a` - 스택 a의 원소를 한 칸씩 위로 옮깁니다. 스택의 첫 번째 원소는 맨 마지막 원소가 됩니다.
    
    **rb : `rotate b` shift up all elements of stack b by 1. The first element becomes the last one.**
    rb : `rotate b` - 스택 b의 원소를 한 칸씩 위로 옮깁니다. 스택의 첫 번째 원소는 맨 마지막 원소가 됩니다.
    
    **rr : `ra` and `rb` at the same time.**
    rr : `ra`와 `rb`를 동시에 수행합니다.
    
    **rra : `reverse rotate a` - shift down all elements of stack a by 1. The last element becomes the first one.**
    rra : `reverse rotate a` - 스택 a의 원소를 한 칸씩 아래로 옮깁니다. 스택의 마지막 원소는 맨 첫 번째 원소가 됩니다.
    
    **rrb : `reverse rotate b` - shift down all elements of stack b by 1. The last element becomes the first one.**
    rrb : `reverse rotate b` - 스택 b의 원소를 한 칸씩 아래로 옮깁니다. 스택의 마지막 원소는 맨 첫 번째 원소가 됩니다.
    
    **rrr : `rra` and `rrb` at the same time.**
    rrr : `rra`와 `rrb`를 동시에 수행합니다.
    

## The “push_swap” program

| Program name
프로그램 이름 | push_swap |
| --- | --- |
| Turn in files
제출할 파일 | *.c, *.h, Makefile |
| Makefile | Name, all, clean, fclean, re |
| Arguments
인자 | stack a: A list of integers
스택 a: 정수 목록 |
| External functs.
사용가능한외부 함수 | • read, write, malloc, free, exit
 • ft_printf and any equivalent YOU coded |
| Libft authorized | Yes
사용 가능 |
| Description
설명 | Sort stacks
스택 정렬 |

**Your project must comply with the following rules:**
프로젝트는 다음 규칙을 준수해야 합니다:

- **You have to turn in a Makefile which will compile your source files. It must not relink.**
소스 파일을 컴파일할 Makefile을 제출해야 합니다. relink되면 안 됩니다.
- **Global variables are forbidden.**
전역 변수는 사용할 수 없습니다.
- **You have to write a program named `push_swap` which will receive as an argument the stack a formatted as a list of integers. The first argument should be at the top of the stack (be careful about the order).**
여러분은 스택 a에 들어갈 정수의 목록을 인자값으로 받는 `push_swap` 프로그램을 작성해야 합니다. 첫 번째로 들어오는 인자가 스택의 맨 위 (top) 에 와야 합니다. (순서에 주의하세요)
- **The program must display the smallest list of instructions possible to sort the stack a, the smallest number being at the top.**
프로그램은 스택 a를 작은 숫자가 스택의 top에 오도록 순서대로 정렬하기 위해 가능한 한 적은 개수의 명령어를 사용해야 하고, 사용한 명령어의 목록을 마지막에 출력하여야 합니다.
- **Instructions must be separaed by a ’\n’ and nothing else.**
명령어는 '\n'으로만 구분되어 출력되어야 합니다.
- **The goal is to sort the stack with the minimum possible number of operations. During defence we’ll compare the number of instructions your program found with a maximum number of operations tolerated. If your program either displays a list too big or if the list isn’t sorted properly, you’ll get no points.**
최종 목표는 스택을 가능한 한 적은 개수의 명령어로 정렬하는 것입니다. 동료평가 시에는 프로그램에서 출력한 명령어의 개수와 평가에서 요구하는 최대 명령어 개수를 비교할 것입니다. 프로그램에서 출력한 명령어 수가 최대 개수를 넘어서거나 제대로 정렬되지 않았을 경우, 점수를 받을 수 없습니다.
- **If no parameters are specified, the program must not display anything and give the prompt back.**
매개 변수가 지정되지 않은 경우 프로그램은 아무것도 표시하지 않고 프롬프트를 반환해야 합니다.
- **In case of error, you must display Error followed by a ’\n’ on the standard error. Errors include for example: some arguments aren’t integers, some arguments are bigger than an integer, and/or there are duplicates.**
오류가 발생했을 경우에는, 표준 출력으로 `Error`와 줄바꿈 문자 (\n) 를 출력하여야 합니다. 오류의 예시로는 특정 인자값이 정수가 아니거나, 정수보다 큰 인자값이 들어오거나, 중복된 인자가 들어오는 경우가 있습니다.

**During the defence we’ll provide a binnary to properly check your program.**
동료평가 시에 사용할 수 있는 Checker 프로그램이 제공됩니다.

 **It will work as follows:**
이 프로그램은 다음과 같이 사용할 수 있습니다 :

```bash
$>ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l
6
$>ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_OS $ARG
OK
```

**If the program `checker_OS` displays `KO`, it means that your `push_swap` came up with a list of instructions that doesn’t sort the list.**
`checker_OS` 프로그램이 `KO`를 출력했다면, 여러분의 `push_swap`이 출력한 명령어 리스트가 정수 배열 정렬에 실패하였다는 의미입니다.

> ⚠️ **The `checker_OS` program is available in the resources of the project on the intranet. You can find in the bonus section of this document a description of how it works.**
`checker_OS` 프로그램은 인트라에서 다운로드 받으실 수 있으며, 어떻게 동작하는지는 과제의 보너스 섹션에서 알아보실 수 있습니다.
>