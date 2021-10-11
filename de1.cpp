#include <iostream>
#include <string>

using namespace std;

class Computer {
  protected:
    string maso,nhan;
  	int tocdo, ram;

  public:
  	void set_maso(string s) {
    	this->maso=s;
  	}
  	void set_nhan(string s) {
    	this->nhan=s;
  	}
  	void set_speed(int c) {
    	this->tocdo = c;
  	}
  	void set_ram(int d) {
    	this->ram = d;
  	}
  	//Xuat
  	string get_maso() {
    	return this->maso;
  	}
  	string get_nhan() {
    	return this->nhan;
 	}
  	int get_speed() {
    	return this->tocdo;
  	}
  	int get_ram() {
    	return this->ram;
  	}
  
  	virtual void input() {
    	cout << "Nhap nhan hieu: ";
    	getline(cin,nhan);
    	cout << "Nhap toc do: ";
    	cin >> tocdo;
    	cout << "Nhap dung luong Ram: ";
    	cin >> ram;
  	}
  	virtual void xuat()
  	{
  		cout <<maso<< "\t" <<nhan<< "\t\t" <<tocdo<< "\t\t" <<ram<< "\t" << endl;
  	}
  	
  	virtual int get_trongluong() {  return 0;	}
  	virtual string get_manhinh() {	return "";	}
};

class Laptop: public Computer {
  int trongluong;
  public:
  void set_trongluong(int a) {
    this->trongluong = a;
  }
  int get_trongluong() {
    return this->trongluong;
  }
  void input() {
    Computer::input();
    cout << "Nhap trong luong Laptop:";
    cin >> trongluong;
  }
};

class Pc: public Computer {
  string manhinh;
  public:
	void set_manhinh(string s) {
    	this->manhinh=s;
  	}

	string get_manhinh() {
    	return this->manhinh;
  	}

  	void input() {
    	Computer::input();
    	fflush(stdin);
    	cout << "Nhap loai man hinh:";
    	getline(cin,manhinh);
  }
};

int main() {
  int n;
  cout << "Nhap N=";
  cin >> n;
  Computer * a[n];
  string t1;

  for (int i = 1; i <= n; i++) {
    fflush(stdin);
    cout << "\nNhap ma so: ";
    getline(cin,t1);

    if (t1[0] == 'L') {

      a[i] = new Laptop;
      a[i]->set_maso(t1);
      a[i]->input();
    } else if (t1[0] == 'P') {
      a[i] = new Pc;
      a[i]->set_maso(t1);
      a[i]->input();
      
    }
  }
  cout << "\nDanh sach cac Laptop nho hon 2.5kg || cac PC ram>=2GB va man hinh LCD :" << endl;
  cout<<"Ma so\t"<<"Nhan hieu\t"<<"Toc do xu ly\t"<<"Dung luong Ram\t"<<endl;
  for (int i = 1; i <= n; i++) {
		if ( (a[i]->get_maso()[0]=='L' && a[i]->get_trongluong() < 2.5 ) ||( (a[i]->get_ram()>=2  && a[i]->get_manhinh()=="LCD") )){
		a[i]->xuat();	
		}
	
  }
  return 0;
}

