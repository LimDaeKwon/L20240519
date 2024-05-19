#include <iostream>
using namespace std;


// ������ enum - ����� �����, �ʱ�ȭ ���ص� �ȴ�.�⺻������ ���ڸ� ���� ���� �ʴ´ٸ� - 0 1 2 ������ ��, ����5���ϸ� 5 6 7.
enum BitFlagState
{
	CONNECT,
	BATTLE,
	FLYING,
	RUNNING
};

int main()
{
	unsigned char Flag = 0; // ��Ʈ ���� �� ��ȣ�� ���־� >> �� �ϴ��� ��ȣ��Ʈ�� �������� �����ϱ� unsigned�� �����ش�.
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

//��Ʈ����
//~bitwise not - ���� ������ ��� ��Ʈ�� ������� 0�� 1, 1�� 0 ���� �ڹٲٴ� �۾�.
//
//& bitwise and �� ������ ��� ��Ʈ ���� ������� and �۾�.
//
//| bitwise or �� ������ ��� ��Ʈ ���� ������� or �۾�.
//
//^ bitwise xor �� ������ ��� ��Ʈ ���� ������� xor �۾�. - �� �� �ڰ� ������ 0, �ٸ��� 1
//�������� xor �ϸ� 0�� ����. + xor�ι��ϸ� �ٽ� �ڱ��ڽ�.
//ex ) ��ȣȭ a = 1, b = 123  
//a = a ^b �ϰ� a = a^b �ٽ� �ϸ� a = 1 ����.

//enum

//������ ����� ����� ���� ���.const�� �ְ�����.
// ���������� enum����� �� ����.
// 
//const�� ��� �� ���� ��쿡 ���� �����Ϸ��� ����ȭ�� �� �� �ִٸ� �޸𸮿� �ø��� �ʰ��� �׳� 1, 2, 3���� ��ü�� �ϰ�����
//���ÿ��ٰ� �ø��ų� �ƴϸ� ������ ���� �ϴ��� �ּҸ� �����ϴ� ����� �ܼ� ġȯ���� �ʰ� �޸𸮿��ٰ� �ö󰡼� �޸� ������ ���� �����Ѵ�.
//
//Enum�� ���������� ���� ������ ����.
//���带 �ϴ� ������ �ܰ迡�� �Ϻ��ϰ� �ܼ� ġȯ�Ǳ� ������ .
//enum���� �ø��ٰ� �ϴ��� �޸𸮻󿡼� ������ �κ��� �ƴ϶� �������� ���̱� ���ؼ� 1�̶�� �� ��ſ� ����Ѱ�.
//const �� ū ���̰� ������ ������ const�� �����̶� �޸𸮸� ��� ���ɼ��� �ִ� �ݸ� enum�� ����.