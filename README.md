# Bulls-and-cows

+ 최근 수정일 : 2020-11-17

+ 숫자야구란?

  + A가 3자리 수를 생각한다. 각 자리는 달라야 하며, 상대방이 이야기한 수와 위치가 같을 경우 스트라이크, 같지만 위치가 다르면 볼, 모든 수가 맞으면 홈런이다.

    A : 1 2 3

    B:  5 6 7

    A : 0b 0s!

    B:  3 2 1

    A:  1s 2b!

    B: 1 2 3

    A: 3s 0b! 홈런!

  + 사용자의 숫자를 입력받아 프로그램이 맞추고, 사용자도 프로그램의 숫자를 맞추는 프로그램을 작성해보자.

+ 소스구현

  ```C++
  #include<iostream>
  #include<cstdlib>
  #include<ctime>
  
  int pro_hit(int &, int &, int &);
  int user_hit(int &, int &, int &);
  
  void input_userNum(int &);
  void input_programNum(int &);
  void _rand(int &);
  
  
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
      input_programNum(base_pro_num);
  
      while(pro_win != 1 && user_win!= 1){
      	user_win = user_hit(_try, base_pro_num, pro_hit_user_num);
          pro_win = pro_hit(_try, base_user_num, user_hit_program_num);
      }
      if(pro_win ==1 && user_win ==1){
      	std::cout<<"draw"<<std::endl;
  	}
      if(pro_win == 1){
      	std::cout<<"program win"<<std::endl;
  	}
  	else{
  		std::cout<<"you win"<<std::endl;
  	}
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
  
  
  void input_programNum(int & program_num){
      _rand(program_num);
  }
  
  
  int user_hit(int& _try, int & program_num, int & user_num){
      int ball, strike;
      int gues;
  
      _try++;
      ball = 0;
      strike = 0;
  
      int program_hund = program_num/100;
      int program_ten = (program_num/10)%10;
      int program_one = program_num%10;
  
      while(1){
          std::cout<<"number: ";
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
  
      gues = user_num;
  
      int user_hund = gues/100;
      int user_ten = (gues/10)%10;
      int user_one = gues%10;
  
      char hit[3];
      hit[0] = user_hund;
      hit[1] = user_ten;
      hit[2] = user_one;
  
      for(int i = 0; i<3; i++){
          if(hit[i]==program_hund || hit[i] == program_ten || hit[i] == program_one){
              if(i == 0 && hit[i] == program_hund){
                  strike++;   
              }
              else if(i == 1 && hit[i] == program_ten){
                  strike++;   
              }
              else if(i == 2 && hit[i] == program_one){
                  strike++;   
              }
              else{
                  ball++;
              }
          }
          
      }
      if(strike == 3){
          std::cout<<strike<<"s "<<ball<<"b"<<std::endl;
          return 1;
      }
  
      else{
          std::cout<<strike<<"s "<<ball<<"b"<<std::endl;
          return -1;
      }
  }
  
  
  
  void _rand(int & num){ // 100~999까지 숫자가 겹치지 않는 랜덤 넘버 생성.
      int hund, ten, one;
      srand(time(NULL));
      
      while(1){
  		num = rand()% 900+100;
  	    
  		hund = num/100;
      	ten = num/10%10;
      	one = num%10;
  
          if( hund != ten && hund != one && ten != one ){
  			//std::cout<<"program_num: "<<num<<std::endl; 
  			break;
  		}
              
      }
  }
  
  ```

  

  