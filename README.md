# AlgorithmTraining
This is an auto push repository for Baekjoon Online Judge created with [BaekjoonHub](https://github.com/BaekjoonHub/BaekjoonHub).

## 1. 문제이해 2. 방법론 기법 생각(전체 탐색, 그리디, 동적계획법, 분할정복법 등등) 3. 방법론 기법을 구체화 할 특정 방법 생각(BFS/DFS, bellmon, warshall, count sort 등등) 4. 어울리는 자료구조 생각

## 입력 값의 범위의 끝부분(맨 앞, 맨 끝)들로 테스트 하는 것을 잊지 말자.

## << endl 사용금지, <<"\n" 사용. endl은 훨씬 시간이 많이 소비된다.

## cin.tie(0); 사용. //cin과 cout을 묶어주지 않음.

## ios::sync_with_stdio(false); 사용. c++ 스타일 코드만 사용되므로 c 스타일의 표준 스트림과 동기화할 필요 없어짐.

## 작은 함수는 inline화 한다. (C++기준) inline 키워드 함수 앞에서 사용.

## 난수 생성 코드 : 
## #include <random> random_device rd; mt19937 gen(rd());
## uniform_int_distribution<int> dis(0,99); int randNum=dis(gen);

## 문제에 특정 자료구조가 사용되었다에 집중하자.해당 자료구조에 맞게 사고하자. 예) " 여러 개의 문서가 쌓인다면 Queue 자료구조에 쌓여서 FIFO - First In First Out - 에 따라 인쇄가 되게 된다. ..."

## cout으로 소수점 정하기 & 반올림 방지. cout<<fixed; cout.precision(원하는 소수점 자리수);

## cout을로 한 줄 받기 (공백 포함, 엔터 미포함함). #include\<string\> string str; getline(cin,str);

## 자료구조에서 조회하는 동작을 할때는 항상 앞서 비어있는지를 확인하는 동작을 하자. 코드 예) if(!stack.empty()) { if(stack.back()==10){ ... } ... } while(!stack.empty()) { stack.front(); ... } 처럼 조건문에 비었는지 확인하고 내용에 조회하는 내용을 넣자.

## 왠만하면 쓸데없이 자료구조를 많이 사용하지 말자. 오히려 더 복잡해질 수 있다.

## 1)"전체적인 입력을 보고 전체적인 결과를 보고 분석하는 방법"도 있지만 2)"입력을 보고 입력을 차례대로 처리해 가며 결과가 만들어지는 '과정'을 생각하며 분석하는 방법"이 유용할 때가 더 많다. 예) 10799번 쇠막대기 문제. 1번방법론] 입력:()(((()))), 결과:6 왜 "()(((())))"는 6이 되냐 2번방법론] 입력:()(((()))). 과정-1:(),0 과정-2:()(,0 과정-3:()((((),3 과정-4:()(((()),4 ...

## for문 보다는 while문을 사용해라.

## 인덱스를 조건문에서 사용할 때 부등호로 비교할 때, 부등호는 "="이 포함된 부등호를 사용해라.

## 1초에 N의 범위가 500: O(N^3) 이하. 2,000: O(N^2) 이하. 100,000: O(NlogN) 이하. 10,000,000: O(N) 이하. 10,000,000,000: O(logN) 이하 가능.
