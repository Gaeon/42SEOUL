| Program name
프로그램 이름 | so_long |
| --- | --- |
| Turn in files
제출할 파일 | Makefile, *.h, *.c, maps, textures |
| Makefile | Name, all, clean, fclean, re |
| Arguments
인자 | A map in format *.ber
*.ber 형식의 맵 |
| External functs.
사용가능한외부 함수 | • open, close, read, write,
malloc, free, perror, strerror, exit
• All functions of the math
library (-lm compiler option, man man 3 math)
• All functions of the MiniLibX
• ft_printf and any equivalent YOU coded |
| Libft authorized | Yes
사용 가능 |
| Description
설명 | You must create a basic 2D game in which a dolphin escapes Earth after eating some fish. Instead of a dolphin, fish, and the Earth, you can use any character, any collectible and any place you want.
여러분은 돌고래가 물고기 몇 마리를 잡아먹은 뒤 지구를 탈출하는 작은 2D 게임을 만들어야 합니다. 굳이 돌고래나 물고기가 될 필요는 없습니다. 주인공이 특정 수집품을 모은 뒤 공간을 떠나는 방식이면 됩니다. |

**Your project must comply with the following rules:**
프로젝트는 다음 규칙을 준수해야 합니다:

- **You must use the MiniLibX. Either the version available on the school machines, or installing it using its sources.**
MiniLibX를 사용해야 합니다. 학교 컴퓨터에서 사용할 수 있는 버전이거나 소스를 사용하여 설치합니다.
- **You have to turn in a Makefile which will compile your source files. It must not relink.**
소스 파일을 컴파일할 Makefile을 제출해야 합니다. relink되면 안 됩니다.
- **Your program has to take as parameter a map description file ending with the .ber extension.**
프로그램은 .ber 확장자로 끝나는 지도 설명 파일을 매개 변수로 사용해야 합니다.

## Game

- **The player’s goal is to collect every collectible present on the map, then escape choosing the shortest possible route.**
플레이어의 목표는 지도에 있는 모든 수집 가능한 존재를 수집한 다음 가능한 가장 짧은 경로를 선택하는 것입니다.
- **The W, A, S, and D keys must be used to move the main character.**
W, A, S, D 키를 사용하여 주인공을 이동해야 합니다.
- **The player should be able to move in these 4 directions: up, down, left, and right.**
선수는 위, 아래, 왼쪽, 오른쪽 네 방향으로 움직일 수 있어야 합니다.
- **The player should not be able to move into walls.**
선수는 벽 안으로 들어갈 수 없습니다.
- **At every move, the current number of movements must be displayed in the shell.**
이동할 때마다 셸에 현재 이동 횟수가 표시되어야 합니다.
- **You have to use a 2D view (top-down or profile).**
2D 보기(톱다운 또는 프로필)를 사용해야 합니다.
- **The game doesn’t have to be real-time.**
게임이 실시간일 필요는 없습니다.
- **Although the given examples show a dolphin theme, you can create the world you want.**
제공된 예는 돌고래 테마를 보여주지만, 원하는 세상을 만들 수 있습니다.

> **⚠️ If you prefer, you can use ZQSD or the arrow keys on your keyboard to move your main character.**
원하시면 ZQSD  또는 키보드의 화살표 키를 사용하여 주인공을 이동할 수 있습니다.
> 

## **Graphic management**

- **Your program has to display the image in a window.**
프로그램에서 이미지를 창에 표시해야 합니다.
- **The management of your window must remain smooth (changing to another window, minimizing, and so forth).**
창 관리가 원활해야 합니다(다른 창으로 변경, 최소화 등).
- **Pressing ESC must close the window and quit the program in a clean way.**
ESC를 누르면 반드시 창이 닫히고 깨끗하게 프로그램을 종료해야 합니다.
- **Clicking on the cross on the window’s frame must close the window and quit the program in a clean way.**
창틀의 십자 기호를 클릭하면 창이 닫히고 깨끗하게 프로그램을 종료해야 합니다.
- **The use of the images of the MiniLibX is mandatory.**
MiniLibX의 이미지는 반드시 사용해야 합니다.

## **Map**

- **The map has to be constructed with 3 components: walls, collectibles, and free space.**
지도는 벽, 수집품, 여유 공간의 3가지 요소로 구성되어야 합니다.
- **The map can be composed of only these 5 characters:**
맵은 다음 5개 문자로만 구성할 수 있습니다:
    
    **0 for an empty space,**                                    빈 공간 0
    **1 for a wall,**                                                             벽 1
    **C for a collectible,**                                            수집품 C
    **E for a map exit,**                                                 지도의 출구 E
    **P for the player’s starting position.**  플레이어의 시작위치 P
    
    **Here is a simple valid map:**
    다음은 간단한 유효 지도입니다:
    
    `**1111111111111
    10010000000C1
    1000011111001
    1P0011E000001
    1111111111111**`
    
- **The map must contain 1 exit, at least 1 collectible, and 1 starting position to be valid.**
지도가 유효하려면 출구가 1개, 수집 가능한 위치가 1개 이상 있어야 합니다.

> **⚠️ If the map contains a duplicates characters (exit/start), you should display an error message.**
지도에 중복된 문자(E / P)가 포함되어 있으면 오류 메시지를 표시해야 합니다.
> 
- **The map must be rectangular.**
지도는 직사각형이어야 합니다.
- **The map must be closed/surrounded by walls. If it’s not, the program must return an error.**
지도는 벽으로 둘러싸여 있어야 합니다. 그렇지 않으면 프로그램에서 오류를 반환해야 합니다.
- **You have to check if there’s a valid path in the map.**
지도에 유효한 경로가 있는지 확인하셔야 합니다.
- **You must be able to parse any kind of map, as long as it respects the above rules.**
이상의 규칙을 준수한 모든 종류의 지도를 파싱할 수 있어야 합니다.
- **Another example of a minimal `.ber` map:**
또 하나의 간단한 `.ber` 지도의 예시입니다:
    
    `**1111111111111111111111111111111111
    1E0000000000000C00000C000000000001
    1010010100100000101001000000010101
    1010010010101010001001000000010101
    1P0000000C00C0000000000000000000C1
    1111111111111111111111111111111111**`
    
- **If any misconfiguration of any kind is encountered in the file, the program must exit in a clean way, and return "Error\n" followed by an explicit error message of your choice.**
지도 파일에서 어떠한 허점이 발견된다면, 프로그램은 "Error\n" 과 여러분이 직접 정한 에러 메시지를 출력한 후 제대로 종료되어야 합니다.