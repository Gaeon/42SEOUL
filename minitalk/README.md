- **You must create a communication program in the form of a client and server.**
    
    여러분은 클라이언트와 서버로 이루어진 통신 프로그램을 작성하여야 합니다.
    
- **The server must be launched first, and after being launched it must display its PID.**
    
    서버가 먼저 실행되어야 하며, 실행된 후에 자기 자신의 PID를 출력하여야 합니다.
    
- **The client will take as parameters:**
    
    클라이언트는 다음과 같은 인자값을 받습니다:
    
    - **The server PID.**
        
        서버 PID
        
    - **The string that should be sent.**
        
        서버로 전송할 문자열
        
- **The client must communicate the string passed as a parameter to the server. Once the string has been received, the server must display it.**
    
    클라이언트는 인자로 들어온 문자열을 서버로 전송할 수 있어야 합니다. 서버에서는 문자열을 수신받은 후, 이를 출력하여야 합니다.
    
- **Communication between your programs should ONLY be done using UNIX signals.**
    
    여러분의 프로그램 끼리의 통신은 **반드시** UNIX 시그널을 이용해서만 이루어져야 합니다.
    
- **The server must be able to display the string pretty quickly. By quickly we mean that if you think it is too long, then it is probably too long (hint: 1 second for 100 characters is COLOSSAL)**
    
    서버는 문자열을 최대한 빠르게 출력하여야 합니다. "빠르게" 라 함은, 만약 문자열 수신이 너무 오래 걸리는 것이 느껴진다면 실제로도 꽤 느리게 동작하는 편이라고 생각하시면 됩니다 (힌트를 드리자면, 100글자를 전송하는데 1초가 소요되면 **굉장히 느린** 겁니다)
    
- **Your server should be able to receive strings from several clients in a row, without needing to be restarted.**
    
    여러분의 서버는 도중에 재시작할 필요 없이, 여러 클라이언트로부터 문자열을 연속적으로 수신받아야 합니다.
    
- **You can only use the two signals `SIGUSR1` and `SIGUSR2`.**
    
    `SIGUSR1` 과 `SIGUSR2` 단 두 개의 시그널만 사용하여야 합니다.
    

> ⚠️ **Linux system do NOT queue signals when you already have pending signal of this type! bonus time?**
> 
> 
> 리눅스 시스템은 같은 유형의 시그널이 이미 보류 중일 경우, 시그널을 대기열에 넣지 않습니다. 보너스 과제 한번 해 보실래요?
>