## ****Overview****

**Here are the things you need to know if you want to succeed this assignment:**
이 과제를 성공하려면 알아야 할 사항은 다음과 같습니다:

- **One or more philosophers sit at a round table.There is a large bowl of spaghetti in the middle of the table.**
철학자들은 둥근 테이블에 앉아있으며, 가운데에는 아주 큰 스파게티 그릇이 놓여 있습니다.
- **The philosophers alternatively eat, think, or sleep.While they are eating, they are not thinking nor sleeping; while thinking, they are not eating nor sleeping;and, of course, while sleeping, they are not eating nor thinking.**
철학자들은 먹거나, 생각하거나, 잠을 잡니다. 철학자가 밥을 먹는 도중에는, 생각하거나 잠을 자지 않습니다. 마찬가지로 잠자는 도중에는 밥을 먹거나 생각할 수 없으며, 생각하는 도중에는 밥을 먹거나 잠들 수 없습니다.
- **There are also forks on the table. There are as many forks as philosophers.**
탁자 위에는 몇 개의 포크가 올려져 있습니다. 포크는 철학자 수만큼 있습니다.
- **Because serving and eating spaghetti with only one fork is very inconvenient, a philosopher takes their right and their left forks to eat, one in each hand.**
스파게티는 포크 하나만으론 집거나 먹기가 어렵기 때문에, 철학자들은 반드시 양 손에 포크를 쥐고 (2개의 포크를 사용하여) 먹어야 합니다.
- **When a philosopher has finished eating, they put their forks back on the table and start sleeping. Once awake, they start thinking again. The simulation stops when a philosopher dies of starvation.**
철학자가 식사를 마쳤을 때, 그들은 포크를 다시 테이블 위에 놓고 잠을 자기 시작합니다. 일단 깨어나면, 그들은 다시 생각하기 시작합니다. 그 시뮬레이션은 철학자가 굶어 죽을 때 멈춥니다.
- **Every philosopher needs to eat and should never starve.**
철학자는 절대로 굶고 있으면 안 됩니다.
- **Philosophers don’t speak with each other.**
철학자들은 서로와 대화할 수 없습니다.
- **Philosophers don’t know if another philosopher is about to die.**
각 철학자는 다른 철학자가 언제 죽는지 알아챌 수 없습니다.
- **No need to say that philosophers should avoid dying!**
철학자들이 최대한 죽지 않도록 설계해야 합니다!

## **Global rules**

**You have to write a program for the mandatory part and another one for the bonus part (if you decide to do the bonus part). They both have to comply with the following rules:
필수 파트에 하나, 보너스 파트에 하나의 프로그램을 만드세요. 두 프로그램은 모두 같은 기본 룰을 따릅니다:**

- **Global variables are forbidden!**
전역변수의 사용은 금지됩니다!
- **Your(s) program(s) should take the following arguments: number_of_philosophers, time_to_die, time_to_eat, time_to_sleep, [number_of_times_each_philosopher_must_eat]**
각 프로그램은 같은 옵션을 가져야 합니다 : 철학자의 수, 철학자의 수명, 밥을 먹는데 걸리는 시간, 잠자는 시간, [각 철학자가 최소한 밥을 먹어야 하는 횟수]
- **number_of_philosophers: The number of philosophers and also the number of forks.
철학자의 수 (number_of_philosophers)**: 테이블에 앉아 있는 철학자의 수와 포크의 수
- **time_to_die (in milliseconds): If a philosopher didn’t start eating time_to_die milliseconds since the beginning of their last meal or the beginning of the sim- ulation, they die.
철학자의 수명 (time_to_die)**: 밀리초 단위로, 철학자가 마지막으로 밥을 먹은 지 'time_to_die' 시간만큼이 지나거나, 프로그램 시작 후 'time_to_die' 시간만큼이 지나면 해당 철학자는 사망합니다.
- **time_to_eat (in milliseconds): The time it takes for a philosopher to eat. During that time, they will need to hold two forks.
밥을 먹는데 걸리는 시간 (time_to_eat)** : 밀리초 단위로, 철학자가 밥을 먹는 데 걸리는 시간입니다. 해당 시간동안, 철학자는 두 개의 포크를 소유하고 있어야 합니다.
- **time_to_sleep (in milliseconds): The time a philosopher will spend sleeping.
잠자는 시간 (time_to_sleep)** : 밀리초 단위로, 잠을 자는 데 소모되는 시간입니다.
- **number_of_times_each_philosopher_must_eat (optional argument): If all philosophers have eaten at least number_of_times_each_philosopher_must_eat times, the simulation stops. If not specified, the simulation stops when a philosopher dies.
각 철학자가 최소한 밥을 먹어야 하는 횟수 (number_of_times_each_philosopher_must_eat)** : 해당 인자값은 선택사항입니다. 모든 철학자가 'number_of_times_each_philosopher_must_eat' 횟수만큼 밥을 먹었다면, 시뮬레이션이 종료됩니다. 해당 값이 명시되어 있지 않다면, 철학자가 한 명이라도 사망할 때까지 시뮬레이션은 계속됩니다.
- **Each philosopher has a number ranging from 1 to number_of_philosophers.**
각 철학자에게는 1부터 'number_of_philosophers' 만큼의 고유 번호가 부여됩니다.
- **Philosopher number 1 sits next to philosopher number number_of_philosophers. Any other philosopher number N sits between philosopher number N - 1 and philoso- pher number N + 1.**
철학자 1번은 철학자 'number_of_philosophers'번 옆에 앉습니다. 그 외에, N번 철학자는 N-1번 철학자와 N+1번 철학자 사이에 앉습니다.
- **About the logs of your program:• Any state change of a philosopher must be formatted as follows:**
철학자의 상태는 다음과 같은 형식으로 출력되어야 합니다. (X는 철학자의 고유 번호로 대체되어야 하며, timestamp_in_ms는 현재 타임스탬프가 밀리초 단위로 표시되어야 합니다.)
    - **timestamp_in_ms X has taken a fork**
    - **timestamp_in_ms X is eating**
    - **timestamp_in_ms X is sleeping**
    - **timestamp_in_ms X is thinking**
    - **timestamp_in_ms X died**

***Replace* timestamp_in_ms *with the current timestamp in milliseconds and* X *with the philosopher number.***

- **A displayed state message should not be mixed up with another message.**
철학자의 상태는 다른 철학자들의 상태와 뒤엉키거나 섞인 상태로 출력되면 안 됩니다.
- **A message announcing a philosopher died should be displayed no more than 10 ms after the actual death of the philosopher.**
철학자의 사망 시점과 이를 출력하기 까지의 틈이 10ms 이상이 되면 안 됩니다.
- **Again, philosophers should avoid dying!**
다시 말하지만, 철학자들이 최대한 죽지 않도록 설계해야 합니다!

<aside>
⚠️ Your program must not have any **data races.**

</aside>

| 프로그램 이름 | philo |
| --- | --- |
| 제출할 파일 | philo/ |
| Makefile | 필요함 |
| 인자 | number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat] |
| 사용가능한 외부 함수 | memset, printf, malloc, free, write, usleep, gettimeofday, pthread_create, pthread_detach, pthread_join, pthread_mutex_init, pthread_mutex_destroy, pthread_mutex_lock, pthread_mutex_unlock |
| 직접 만든 libft | 사용 불가 |
| 설명 | 스레드와 뮤텍스를 사용한 철학자의 구현 |

**The specific rules for the mandatory part are:**
이 버전에서만 적용되는 규칙은 다음과 같습니다:

- **Each philosopher should be a thread.**
- 각 철학자는 스레드로 구현되어 있어야 합니다.
- **There is one fork between each pair of philosophers. Therefore, if there are several philosophers, each philosopher has a fork on their left side and a fork on their right side. If there is only one philosopher, there should be only one fork on the table.**
두 철학자 사이에 한 개의 포크가 존재하므로, 철학자가 여러명일 경우 각 철학자의 왼쪽과 오른쪽에 포크가 하나씩 존재해야 합니다.
- **To prevent philosophers from duplicating forks, you should protect the forks state with a mutex for each of them.**
철학자가 포크를 복제하는 것을 막기 위해서, 각 포크의 현재 상태를 뮤텍스를 이용하여 보호해주어야 합니다.