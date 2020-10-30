#include<iostream>
#include<cstdlib>
#include<ctime>

int pro_hit(int &, int &, int &);

void input_userNum(int &);


int mean_value[3] = {-1,-1,-1};
int trash_value[10] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
int i = 2;
int ball_num =-1;
int ball2_num = -1;

int main(){
    int base_user_num;
    int base_pro_num;

    int user_hit_program_num;
    int pro_hit_user_num;

    int _try = 0;
    int pro_win = 0;
    int user_win = 0;

    input_userNum(base_user_num);

    pro_win = pro_hit(_try, base_user_num, user_hit_program_num);

    return 0;
}

int pro_hit(int &_try, int &user_num, int & program_num){
    int ball = 0, strike = 0;
   
    int user_hund = user_num/100;
    int user_ten = (user_num/10)%10;
    int user_one = user_num%10;
    
    int new_num;
	
    if(trash_value[0] == -1){
        // _rand(program_num);
        while(1){
            int num = rand()%900+100;
            // printf("%d\n", num);
            int hund = num/100;
            int ten = num/10%10;
            int one = num%10;

            if( hund != ten && hund != one && ten != one ){
                program_num = num;
                break;
            }
        }

        int pro_hund = program_num/100;
        int pro_ten = (program_num/10)%10;
        int pro_one = program_num%10;

        char hit[3];
        hit[0] = pro_hund;
        hit[1] = pro_ten;
        hit[2] = pro_one;

        for(int i = 0; i<3; i++){
            if(hit[i]==user_hund || hit[i] == user_ten || hit[i] == user_one){
                if(i == 0 && hit[i] == user_hund){
                    strike++;   
                }
                else if(i == 1 && hit[i] == user_ten){
                    strike++;   
                }
                else if(i == 2 && hit[i] == user_one){
                    strike++;   
                }
                else{
                    ball++;
                }
            }
        }

        if(strike == 0 && ball == 0){
            std::cout<<program_num<<"    ";
            std::cout<<strike<<"s "<<ball<<"b"<<std::endl;

            trash_value[0] = pro_hund;
            trash_value[1] = pro_ten;
            trash_value[2] = pro_one;
            return -1;

        }
        else if(strike == 3){
            std::cout<<program_num<<"    ";
            std::cout<<strike<<"s "<<ball<<"b"<<std::endl;
            return 1;
        }
        else{
            std::cout<<program_num<<"    ";
            std::cout<<strike<<"s "<<ball<<"b"<<std::endl;
            return -1;
        }
    }
    else if(mean_value[0] == -1){
        while(1){
            int num = rand()%9+1;
            // printf("%d\n", num);
            int hund = num/100;
            int ten = num/10%10;
            int one = num%10;
            new_num = num;
            if(new_num!=ball_num&&new_num != trash_value[0]&&new_num != trash_value[1]&&new_num != trash_value[2]&&new_num != trash_value[3]&&new_num != trash_value[4]&&new_num != trash_value[5]&&new_num != trash_value[6]&&new_num != trash_value[7]&&new_num != trash_value[8]){
                std::cout<<new_num<<(int)trash_value[1]<<(int)trash_value[2]<<"    ";
                break;
            }
        }

        if(new_num != user_one && new_num != user_ten && new_num !=user_hund){
            i++;
            trash_value[i] = new_num;
        }
        else{
            if(new_num == user_hund){
                strike ++;
            }
            else{
            	ball ++;
			}
        }
        if(strike == 1){
            std::cout<<strike<<"s "<<ball<<"b"<<std::endl;
            mean_value[0] = new_num;
            i++;
            trash_value[i] = new_num;
            return -1;
        }
        else if(ball ==1){
        	ball_num = new_num;
            std::cout<<strike<<"s 1b"<<std::endl;
            return -1;
		}
        else{
            std::cout<<strike<<"s 0b"<<std::endl;
            return -1;
        }
    }

    else if (mean_value[1]==-1){
        while(1){
        	if(ball_num !=-1){
        		std::cout<<(int)mean_value[0]<<ball_num<<trash_value[2]<<"    ";
        		new_num = ball_num;
        		ball_num = -1;
        		break;
			}
            int num = rand()%9+1;
            // printf("%d\n", num);
            int hund = num/100;
            int ten = num/10%10;
            int one = num%10;

            new_num = num;
            if(new_num != trash_value[0]&&new_num != trash_value[1]&&new_num != trash_value[2]&&new_num != trash_value[3]&&new_num != trash_value[4]&&new_num != trash_value[5]&&new_num != trash_value[6]&&new_num != trash_value[7]&&new_num != trash_value[8]){
                std::cout<<(int)mean_value[0]<<new_num<<(int)trash_value[2]<<"    ";
                break;
            }
        }

        if(new_num != user_one && new_num != user_ten && new_num !=user_hund){
            i++;
            trash_value[i] = new_num;
        }
        else{
            if(new_num == user_ten){
                strike ++;
            }
            else{
                mean_value[2] = new_num;
                ball ++;
            }
        }
        if(strike == 1){
            std::cout<<"2s 0b"<<std::endl;
            mean_value[1] = new_num;
            i++;
            trash_value[i] = new_num;
            
            return -1;
        }
        else{
            std::cout<<"1s "<<ball<<"b"<<std::endl;
            return -1;
        }

    }

    else if (mean_value[2]==-1){
        while(1){
            int num = rand()%9+1;
            // printf("%d\n", num);
            int hund = num/100;
            int ten = num/10%10;
            int one = num%10;

            new_num = num;
            if(new_num != trash_value[0]&&new_num != trash_value[1]&&new_num != trash_value[2]&&new_num != trash_value[3]&&new_num != trash_value[4]&&new_num != trash_value[5]&&new_num != trash_value[6]&&new_num != trash_value[7]&&new_num != trash_value[8]){
                std::cout<<(int)mean_value[0]<<(int)mean_value[1]<<new_num<<"    ";
                break;
            }
        }
        if(new_num != user_one){
            i++;
            trash_value[i] = new_num;
        }
        else if(new_num == user_one){
            strike ++;
        }
        if(strike == 1){
            std::cout<<"3s 0b"<<std::endl;
            mean_value[2] = new_num;
            return 1;
        }
        else{
            std::cout<<"2s 0b"<<std::endl;
            return -1;
        }

    }
    
    else{
        std::cout<<(int)mean_value[0]<<(int)mean_value[1]<<(int)mean_value[2]<<"    ";
        std::cout<<"3s 0b"<<std::endl;    
        return 1;
    }   
}


void input_userNum(int & user_num){
    while(1){
        std::cout<<"your number: ";
        std::cin>>user_num; 

        int user_hund = user_num/100;
        int user_ten = (user_num/10)%10;
        int user_one = user_num % 10;

        if(user_hund == 0){
            std::cout<<"0 can't located at first"<<std::endl;
        }

        else if(user_hund == user_ten || user_hund == user_one || user_ten == user_one){
            std::cout<<"No repetition"<<std::endl;;
        }
        else{
            break;
        }
    }
}

