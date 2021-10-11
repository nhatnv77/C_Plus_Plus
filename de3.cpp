#include <iostream>
using namespace std;

class Hinhchunhat{
	protected:
		float chieudai,chieurong;
	public:
		virtual float tinh()
		{
			return chieudai*chieurong;
		}
};

class Hinhhop: public Hinhchunhat{
	private:
		float chieucao;
	public:
		Hinhhop(){
			this->chieudai=0;
			this->chieurong=0;
			this->chieucao=0;
		}
		Hinhhop(float a,float b, float c)
		{
			this->chieudai=a;
			this->chieurong=b;
			this->chieucao=c;
		}
		float tinh()
		{
			return Hinhchunhat::tinh()*chieucao;
		}
};

int main()
{
	float a,b,c;
	cout<<"Nhap chieu dai: "; cin>>a;
	cout<<"Nhap chieu rong: "; cin>>b;
	cout<<"Nhap chieu cao: "; cin>>c;
	Hinhhop x(a,b,c);
	cout<<"The tich hinh hop chu nhat la: "<<x.tinh();
	
	return 0;
}
