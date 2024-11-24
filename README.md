# AlgorithmTraining
This is an auto push repository for Baekjoon Online Judge created with [BaekjoonHub](https://github.com/BaekjoonHub/BaekjoonHub).

## << endl 사용금지, <<"\n" 사용. endl은 훨씬 시간이 많이 소비된다.

## cin.tie(0); 사용. //cin과 cout을 묶어주지 않음.

## ios::sync_with_stdio(false); 사용. c++ 스타일 코드만 사용되므로 c 스타일의 표준 스트림과 동기화할 필요 없어짐.

## 문제에 특정 자료구조가 사용되었다에 집중하자.해당 자료구조에 맞게 사고하자. 예) " 여러 개의 문서가 쌓인다면 Queue 자료구조에 쌓여서 FIFO - First In First Out - 에 따라 인쇄가 되게 된다. ..."

## cout으로 소수점 정하기 & 반올림 방지. cout<<fixed; cout.precision(원하는 소수점 자리수);

## cout을로 한 줄 받기 (공백 포함, 엔터 미포함함). #include\<string\> string str; getline(cin,str);

## 자료구조에서 조회하는 동작을 할때는 항상 앞서 비어있는지를 확인하는 동작을 하자. 코드 예) if(!stack.empty()) { if(stack.back()==10){ ... } ... } while(!stack.empty()) { stack.front(); ... } 처럼 조건문에 비었는지 확인하고 내용에 조회하는 내용을 넣자.

## 왠만하면 쓸데없이 자료구조를 많이 사용하지 말자. 오히려 더 복잡해질 수 있다.
