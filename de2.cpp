#include <iostream>
#include <string>
using namespace std;

class	canbo{
	protected:
		string ten,trinhdo;
		int tuoi;
	public:
		void set_ten( string s){
			this->ten=s;
		}
		void set_tuoi( int t){
			this->tuoi=t;
		}
		void set_td( string s1)
		{
			this->trinhdo=s1;
		}
		
		string get_ten(){
			return this->ten;
		}
		int get_tuoi(){
			return this->tuoi;
		}
		string get_td(){
			return this->trinhdo;
		}
		virtual void input(){ }
		
		void xuat(){
			cout<<"Ten: "<<ten<<endl;
			cout<<"Tuoi: "<<tuoi<<endl;
			cout<<"Trinh do: "<<trinhdo<<endl;
		}
		virtual string get_ck() {
		return "";		//da hinh mac dinh
		}
		virtual int get_nam() { 
		return 0;  //da hinh mac dinh
		}
		
};

class	dieuduong: public canbo{
	private:
	int nam;
	public:
		void set_nam( int t){
			this->nam=t;
		}
		int get_nam(){
			return this->nam;
		}
		void input()
		{
			cout<<"Nhap so nam kinh nghiem: ";
			cin>>this->nam;
		}
};

class bacsi: public canbo{
	private:
	string chuyenkhoa;
	public:
		void set_ck( string s){
			this->chuyenkhoa=s;
		}
		string get_ck (){
			return this->chuyenkhoa;
		}
		void input()
		{
			fflush(stdin);
			cout<<"Nhap chuyen khoa: ";
			getline(cin,this->chuyenkhoa);
		}
};

int main(){
	int n;
	cout<<"Nhap so luong N= "; cin>>n;
	canbo* a[n];
	int t;
	string s1,s2;
	for (int i=1; i<=n;i++)
	{
			fflush(stdin);
			cout<<"\nNhap ten: "; getline(cin,s1);
			cout<<"Nhap tuoi: "; cin>>t;
			fflush(stdin);
			cout<<"Nhap trinh do: "; getline(cin,s2);
			
		if (s2=="dieuduong" || s2=="dieu duong")
		{
			a[i] = new dieuduong;
			a[i]->set_ten(s1);
			a[i]->set_tuoi(t);
			a[i]->set_td(s2);
			a[i]->input();
			
		}
		
	else if ( s2=="bacsi" || s2=="bac si")
		{
			a[i] = new bacsi;
			a[i]->set_ten(s1);
			a[i]->set_tuoi(t);
			a[i]->set_td(s2);
			a[i]->input();
		}
	}
	
	cout<<endl;
	cout<<"Danh sach canm bo y te duoc chon: "<<endl;
	for (int i=1; i<=n; i++)
	{
		if (a[i]->get_ck()=="mat" || a[i]->get_nam() >5)
		a[i]->xuat();
	}
	return 0;
}
