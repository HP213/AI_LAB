#include<iostream>
#include <cstdlib>
char board[3][3];

struct result{
	int i;
	int j;
};

result checkPosition(int position){
	result final;
	switch (position){
		case 1:
			final = {0 , 0};
			return final;
		case 2:
			final = {0 , 1};
			return final;
			break;
		case 3:
			final = {0 , 2};
			return final;
			break;
		case 4:
			final = {1 , 0};
			return final;
			break;
		case 5:
			final = {1 , 1};
			return final;
			break;
		case 6:
			final = {1 , 2};
			return final;
			break;
		case 7:
			final = {2 , 0};
			return final;
			break;
		case 8:
			final = {2 , 1};
			return final;
			break;
		case 9:
			final = {2 , 2};
			return final;
			break;
		
	}
}

int makeMove(int position, char value){
	switch (position){
		case 1:
			if(board[0][0] == 'x' || board[0][0] == 'o')
			return 0;
			board[0][0] = value;
			break;
		case 2:
			if(board[0][1] == 'x' || board[0][1] == 'o')
			return 0;
			board[0][1] = value;
			break;
		case 3:
			if(board[0][2] == 'x' || board[0][2] == 'o')
			return 0;
			board[0][2] = value;
			break;
		case 4:
			if(board[1][0] == 'x' || board[1][0] == 'o')
			return 0;
			board[1][0] = value;
			break;
		case 5:
			if(board[1][1] == 'x' || board[1][1] == 'o')
			return 0;
			board[1][1] = value;
			break;
		case 6:
			if(board[1][2] == 'x' || board[1][2] == 'o')
			return 0;
			board[1][2] = value;
			break;
		case 7:
			if(board[2][0] == 'x' || board[2][0] == 'o')
			return 0;
			board[2][0] = value;
			break;
		case 8:
			if(board[2][1] == 'x' || board[2][1] == 'o')
			return 0;
			board[2][1] = value;
			break;
		case 9:
			if(board[2][2] == 'x' || board[2][2] == 'o')
			return 0;
			board[2][2] = value;
			break;
		
	}
}

void display(){
	for(int i = 0; i<3; i++){
		for(int j=0; j<3; j++){
			std::cout<<board[i][j];
			if(j<2){
			std::cout<<"|";
		}
		}
		std::cout<<std::endl;
		for(int k=0; k < 3 && i<2; k++){
			std::cout<<"_"<<" ";
		}
		std::cout<<std::endl;
	}
}

	int checkLossing(){
		for(int i=0; i<3; i++){
			int countX = 0;
			int countO = 0;
			for(int j=0; j < 3; j++){
				if(board[i][j] == 'x')
				countX++;
				else if(board[i][j] == 'o')
				countO++;
			}
			if(countX == 2 && countO == 0){
			return 0;	
			}
		}
		
		for(int i=0; i<3; i++){
			int countX = 0;
			int countO = 0;
			for(int j=0; j < 3; j++){
				if(board[j][i] == 'x')
				countX++;
				else if(board[j][i] == 'o')
				countO++;
			}
			if(countX == 2 && countO == 0){
			return 0;	
			}
		}
		
		int countX = 0;
		int countO = 0;
		for(int i=0; i<3; i++){
			if(board[i][i] == 'x')
			countX++;
			else if(board[i][i] == 'o')
			countO++;
		}
		if(countX == 2 && countO == 0)
			return 0;
		
		countX = countO = 0;
		if(((board[0][2] == 'x') && board[0][2] == board[2][0]) || ((board[0][2] == 'x') && board[0][2] == board[1][1]) || ((board[1][1] == 'x') && board[1][1] == board[2][0])){
			countX = 2;	
		}
		if(board[0][2] == 'o' || board[2][0] == 'o' ||board[1][1] == 'o' ){
			countO = 1;
		}
		if(countX == 2 && countO == 0){
			
			return 0;
	}
		
		return 1;
	}
	
	int checkWinning(){
		for(int i=0; i<3; i++){
			int countX = 0;
			int countO = 0;
			for(int j=0; j < 3; j++){
				if(board[i][j] == 'x')
				countX++;
				else if(board[i][j] == 'o')
				countO++;
			}
			if(countX == 0 && countO == 3)
			return 1;	
		}
		int countX = 0;
		int countO = 0;
		for(int i=0; i<3; i++){
			if(board[i][i] == 'x')
			countX++;
			else if(board[i][i] == 'o')
			countO++;
		}
		if(countX == 0 && countO == 3)
			return 1;
		
		countX =countO = 0;
		if(board[0][2] == board[2][0] == 'o' || board[0][2] == board[1][1] == 'o' || board[2][0] == board[1][1] == 'o')
		countO = 2;
		if(board[0][2] == 'x' || board[2][0] == 'x' ||board[1][1] == 'x' ){
			countX = 1;
		}
		if(countX == 0 && countO == 3)
			return 1;
		
		return 0;
	}

void backtrack(int position){
	char ch = '0' + position;
	result place = checkPosition(position);
	board[place.i][place.j] = ch;
}

int computerMove(){
	int position = 0;
	for(int i=0; i< 3; i++){
		for(int j=0; j< 3; j++){
			if(board[i][j] == 'x'){
				position++;
			}	
		}
	}
	int done = 1;
	if(position == 0){
		int value = rand()%10;
		if(value > 0 && value < 9){
			makeMove(value, 'o');
		}
	}
	
	while(position == 1 && done){
		int value = rand()%10;
		if(value > 0 && value < 9 && (value%2 == 0 || value == 5)){
			if(makeMove(value, 'o'))
			done = 0;
		}
	}
	
	if(position > 1){
		char ch;
		for(int value = 1; value < 10 && done; value++){
			if(makeMove(value , 'o')){
				if(checkWinning()){
					done = 0;
				}else{
					backtrack(value);
				}
			}
		}
		
		for(int value = 1; value < 10 && done; value++){
			if(makeMove(value, 'o')){
				if(!checkLossing()){
					backtrack(value);
				}else if(checkLossing()){
					done = 0;
				}
			}
		}
		if(done == 1){
			std::cout<<"You Win, we lost\n";
		}
	}
}

int main(){
	int k = 1;
	int count = 1;
	char confirmation;
	std::cout<<"You want to start first? Y/N :";
	std::cin>>confirmation;
	std::cout<<"Entered value is : "<<confirmation;
	for(int i=0; i< 3; i++){
		for(int j=0; j<3; j++){
			board[i][j] = '0' + k;
			k++;
		}
	}
	std::cout<<std::endl;
	display();
	if(confirmation == 'y' || confirmation == 'Y'){
		while(count < 10){
			int position;
			std::cout<<"Enter position to place your X :";
			std::cin >> position;
			if(position > 0 && position < 10){
				makeMove(position, 'x') && count++;
				computerMove();
				count++;
//				system("cls");
				display();	
			}
			
		}
	}else{
		while(count < 10){
			computerMove();
			count++;
			display();
			int position;
			std::cout<<"Enter position to place your X :";
			std::cin >> position;
			if(position > 0 && position < 10 && count < 10){
				makeMove(position, 'x') && count++;
//				system("cls");
				display();	
			}
			
		}
	}
}
