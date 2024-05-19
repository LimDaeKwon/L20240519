#include <iostream>
using namespace std;


// 열거형 enum - 상수값 만들기, 초기화 안해도 된다.기본적으로 숫자를 지정 하지 않는다면 - 0 1 2 순서로 쫙, 시작5로하면 5 6 7.
enum BitFlagState
{
	CONNECT,
	BATTLE,
	FLYING,
	RUNNING
};

int main()
{
	unsigned char Flag = 0; // 비트 연산 시 부호를 엎애야 >> 를 하더라도 부호비트가 딸려오지 않으니까 unsigned를 붙혀준다.
	Flag = 1 << CONNECT;
	Flag |= 1 << BATTLE;
	Flag |= 1 << FLYING;
	Flag |= 1 << RUNNING;

	bool BattleOrRunning = ((Flag & (1 << BATTLE)) && (Flag & (1 << RUNNING)) != 0);
	cout << BattleOrRunning << endl;

	Flag &= ~(1 << RUNNING);

	BattleOrRunning = ((Flag & (1 << BATTLE)) && (Flag & (1 << RUNNING)) != 0);
	cout << BattleOrRunning << endl;


	return 0;
}

//비트연산
//~bitwise not - 단일 숫자의 모든 비트를 대상으로 0은 1, 1은 0 으로 뒤바꾸는 작업.
//
//& bitwise and 두 숫자의 모든 비트 쌍을 대상으로 and 작업.
//
//| bitwise or 두 숫자의 모든 비트 쌍을 대상으로 or 작업.
//
//^ bitwise xor 두 숫자의 모든 비트 쌍을 대상으로 xor 작업. - 두 숫 자가 같으면 0, 다르면 1
//같은숫자 xor 하면 0이 나옴. + xor두번하면 다시 자기자신.
//ex ) 암호화 a = 1, b = 123  
//a = a ^b 하고 a = a^b 다시 하면 a = 1 나옴.

//enum

//정수를 상수로 만들고 싶을 경우.const도 있겠지만.
// 실질적으로 enum방법이 더 좋아.
// 
//const를 사용 할 떄는 경우에 따라서 컴파일러가 최적화를 할 수 있다면 메모리에 올리지 않고도 그냥 1, 2, 3으로 대체를 하겠지만
//스택에다가 올리거나 아니면 전역에 선언 하더라도 주소를 참조하는 경우라면 단순 치환되지 않고 메모리에다가 올라가서 메모리 공간을 조금 낭비한다.
//
//Enum은 실질적으로 위의 단점이 없다.
//빌드를 하는 컴파일 단계에서 완벽하게 단순 치환되기 떄문에 .
//enum값을 늘린다고 하더라도 메모리상에서 잡히는 부분이 아니라 가독성을 높이기 위해서 1이라는 값 대신에 사용한것.
//const 랑 큰 차이가 있지는 않지만 const는 조금이라도 메모리를 잡는 가능성이 있는 반면 enum은 없다.
