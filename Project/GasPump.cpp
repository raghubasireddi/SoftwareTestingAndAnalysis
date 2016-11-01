class GasPump {
public:
GasPump();					
int Activate (int a, int b); 
int Start();				
int PayCredit();			
int Reject();				
int Cancel();				
int Approved();				
int PayCash(int c);			
int Regular();				
int Super();				
int StartPump();			
int PumpGallon();			
int StopPump();				
int NoReceipt();			
int Receipt();				
int TurnOff();				

private:
int Rprice;
int Sprice;
int w;
int price;
int G;
int total;
int cash;
int s;
};

GasPump::GasPump(){
	Rprice=0;
	Sprice=0;
	w=0;
	price=0;
	G=0;
	total=0;
	cash=0;
	s=-1;
}

int GasPump::Activate (int a, int b){
	if ((s==-1)&&(a>0)&&(b>0)) {
		s=0;
		Rprice=a;
		Sprice=b;
		cout<<"GAS PUMP IS ON"<<endl;
		return 1;
	} else return 0;

};

int GasPump::Start(){
	if (s==0) {
		s=1;
		cout<<"WELCOME!!!"<<endl;
		cout<<"DO YOU WANT TO PAY BY CASH OR CREDIT CARD?"<<endl;
		return 1;
	} else return 0;

};

int GasPump::PayCredit() {
	if (s==1) {
		s=2;
		cout<<"CHECKING CREDIT CARD."<<endl;
		return 1;
	} else return 0;	
};

int GasPump::Reject() {
	if (s==2) {
		s=0;
		cout<<"CREDIT CARD IS REJECTED."<<endl;
		return 1;
	} else return 0;	
};


int GasPump::Approved() {
	if (s==2) {
		s=3;
		w=1;
		cout<<"CREDIT CARD APPROVED."<<endl;
		cout<<"SELECT TYPE OF GASOLINE:"<<endl;
		cout<<"a. REGULAR"<<endl;
		cout<<"b. SUPER"<<endl;
		return 1;
	} else return 0;	
};

int GasPump::Cancel() {
	if (s==3) {
		s=0;
		cout<<"TRANSACTION IS CANCELLED."<<endl;
		if (w==0) cout<<"$"<<cash<<" OF CASH IS RETURNED"<<endl; 
		return 1;
	} else return 0;	
};


int GasPump::PayCash(int c) {
	if ((s==1)&&(c>0)) {
		s=3;
		w=0;
		cash=c;
		cout<<"SELECT TYPE OF GASOLINE:"<<endl;
		cout<<"a. REGULAR"<<endl;
		cout<<"b. SUPER"<<endl;
		return 1;
	} else return 0;	
};


int GasPump::Regular() {
	if (s==3) {
		s=4;
		cout<<"REGULAR IS SELECTED."<<endl;
		price=Rprice;
		return 1;
	} else return 0;	
};

int GasPump::Super() {
	if (s==3) {
		s=4;
		cout<<"SUPER IS SELECTED."<<endl;
		price=Sprice;
		return 1;
	} else return 0;	
};


int GasPump::StartPump() {
	if (s==4) {
		s=5;
		G=0;
		total=0;
		cout<<"PUMP IS READY TO DISPOSE "<<endl;
		cout<<"# OF GALLONS PUMPED: "<<G<<endl;
		cout<<"TOTAL CHARGE: $"<<total<<endl;
		return 1;
	} else return 0;	
};


int GasPump::PumpGallon() {
	if (s==5) {
		if ((w==1)||((cash>=price*(G+1))&&(w==0))) { 
			G=G+1;
			total=G*price;
			cout<<"# OF GALLONS PUMPED: "<<G<<endl;;
			cout<<"TOTAL CHARGE: $"<<total<<endl;
			cout<<"CONTINUE PUMPING"<<endl;
			return 1;
		} else if ((w==0)&&(cash<price*(G+1))) {
			s=6;
			cout<<"PUMP STOPPED. NOT SUFFICIENT FUNDS. "<<endl;
			cout<<"# OF GALLONS PUMPED: "<<G<<endl;
			cout<<"TOTAL CHARGE: $"<<total<<endl;
			if ((w==0)&&(total<cash)) cout<<"$"<<cash-total<<" OF CASH IS RETURNED"<<endl; 
			cout<<"DO YOU WANT A RECEIPT?"<<endl;
			return 1;
		};
	};  
	return 0;	
};


int GasPump::StopPump() {
	if (s==5) {
		s=6;
		cout<<"PUMP STOPPED. "<<endl;
		cout<<"# OF GALLONS PUMPED: "<<G<<endl;
		cout<<"TOTAL CHARGE: $"<<total<<endl;
		if ((w==0)&&(total<cash)) cout<<"$"<<cash-total<<" OF CASH IS RETURNED"<<endl; 
		cout<<"DO YOU WANT A RECEIPT?"<<endl;
		return 1;
	} else return 0;	
};

int GasPump::NoReceipt() {
	if (s==6) {
		s=0;
		cout<<"NO RECEIPT IS PRINTED "<<endl;
		return 1;
	} else return 0;	
};


int GasPump::Receipt() {
	if (s==6) {
		s=0;
		cout<<"RECEIPT IS PRINTED: "<<endl;
		cout<<"# OF GALLONS PUMPED: "<<G<<endl;
		cout<<"TOTAL CHARGE: $"<<total<<endl;
		return 1;
	} else return 0;	
};


int GasPump::TurnOff() {
	if (s==0) {
		s=-2;
		cout<<"GAS PUMP IS TURNED OFF "<<endl;
		return 1;
	} else return 0;	
};

