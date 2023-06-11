/*  Kyutza Lopez
    COP 3223C
    Assignment 7
    2/14/23     */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int numDigits(int max);
double arithGame (int max, int quantity, int op);
double guessGame(int max);
int scoring (float t);

int main(){
    int selection = 0; int totalScore = 0;

    while (selection != 4){

        printf("Please make a selection from the following:\n1. Play Arithmetic Game.\n2. Play Guessing Game\n3. Print Score\n4. Quit.\n");
        scanf("%i", &selection);

        if (selection == 1){
            int max; int quantity; int op; 
            printf("Select option 1 or 2 from the menu:\n");
            printf("1) Addition\n2) Multiplication\n");
            scanf("%i", &op);
            printf("What is your maximum value?\n");
            scanf("%i", &max);
            printf("How many questions do you want?\n");
            scanf("%i", &quantity);

            float scoreIntime = arithGame (max, quantity, op);
            //printf("Your score for the round in seconds is %.3lf.\n", scoreIntime);

            int score = scoring (scoreIntime);
            printf("Your score for the round is %i\n", score);

            totalScore += score;
}
        else if (selection == 2){
            int max;
            printf("Enter the maximum number for the game.\n");
            scanf("%i", &max);

            float scoreIntime = guessGame(max);
            //printf("Your score for the round in seconds is %.3lf.\n", scoreIntime);

            int score = scoring (scoreIntime);
            printf("Your score for the round is %i\n", score);

            totalScore += score;
    }
        else if (selection == 3){
            printf("Your total score is: %i\n", totalScore);

        }

        else if(selection == 4){
            printf("Game over!\n");
        }

        
        else {
            printf("This is not an option. Try again.\n");
        }
    }
}


double arithGame (int max, int quantity, int op) {
    int lower = 1; // setting lower because numbers will always range from 1 to max
    int r1, r2; // the numbers random funciton will create to add/multiply
    int countWrong = 0; 
    int timeSpent;//to count how many wrong questions for total penalty seconds
   
    if (op == 1){ // addition problems 
       
        int start = time(0); //starting time to count
        srand(time(0));
        for (int i = 1; i <= quantity; i++){ //looping the amount of questions the user asked for
            r1 = (rand() % (max - lower + 1)) + lower;
            r2 = (rand() % (max - lower + 1)) + lower;
            
            int rightAnswer = r1 + r2;
            int answerAttempt;
            printf("%i + %i\n", r1, r2);
            scanf("%i", &answerAttempt);

            if (answerAttempt == rightAnswer){
                printf("Correct, great job!\n");
            }
                else {
                printf("Sorry, that's incorrect, the answer is %i.\n", rightAnswer);
                countWrong += 1;
                }
    }
        int end = time(0); // ending time to count
        timeSpent = end - start;
        double avgTime = timeSpent / (double)quantity;
        printf("Your code took %d seconds.\n", timeSpent);
        printf("You took an average of %.6lf seconds per question.\n", avgTime);
        
    } //end of option 1
    else  { //multiplicaiton problems
        int start = time(0); //starting time to count
        srand(time(0));
        for (int i = 1; i <= quantity; i++){ //looping the amount of questions the user asked for
            r1 = (rand() % (max - lower + 1)) + lower;
            r2 = (rand() % (max - lower + 1)) + lower;
            
            int rightAnswer = r1 * r2;
            int answerAttempt;
            printf("%i * %i\n", r1, r2);
            scanf("%i", &answerAttempt);

            if (answerAttempt == rightAnswer){
                printf("Correct, great job!\n");
            }
                else {
                printf("Sorry, that's incorrect, the answer is %i.\n", rightAnswer);
                countWrong += 1;
                } 
    }
    
    // calculating time and score
        int end = time(0); //ending time to count
        timeSpent = end - start;
        double avgTime = timeSpent / (double)quantity;
        printf("Your code took %d seconds.\n", timeSpent);
        printf("You took an average of %.6lf seconds per question.\n", avgTime);
       
}// end of option 2

        int penaltySeconds = countWrong * 5; // for every one question wrong, it's 5 seconds added
        float scoreIntime = ((timeSpent + penaltySeconds) / (float)quantity);
        
        return scoreIntime;
}

double guessGame(int max){
    int guess; int answer; int lower = 1; int count = 0;

    srand(time(0));
    answer = (rand() % (max - lower + 1)) + lower;

    printf("Enter the guess!\n");
    scanf("%i", &guess);

    int start = time(0);
    count++;
    
    while (guess != answer){
        if (guess > answer){
            printf("Your guess is too high, try again.\n");
            printf("Enter the guess!\n");
            scanf("%i", &guess);      
         }
        else if (guess < answer){
            printf("Your guess is too low, try again.\n");
            printf("Enter the guess!\n");
            scanf("%i", &guess);    
        }
    count += 1;
}  
    int end = time(0);

    int timeSpent = end - start;
    printf("Great, you guessed the correct number %i in %i guesses in %d seconds.\n", answer, count, timeSpent);


    int digits = numDigits(max); // calculating number of digits   
    float scoreIntime = (timeSpent / (float)(2 * digits)) ;
    
    return scoreIntime;
}

int numDigits (int max){ // to calculate number of digits
    int count = 0;
    while (max != 0){
        max = max / 10;
        count ++;
    }
    return count;
}

int scoring (float t){ // function to calculate score
    int score;
    if (t < 1){
        score = 10;
    }   
    else if (1 <= t && t < 2){
        score = 9;
    } 
    else if (2 <= t && t < 3){
        score = 8;
    }
    else if (3 <= t && t < 4){
        score = 7;
    }
    else if (4 <= t && t < 5){
        score = 6;
    }
    else if (5 <= t && t < 6){
        score = 5;
    }
    else if (6 <= t&& t < 7){
        score = 4;
    }
    else if (7 <= t && t < 8){
        score = 3;
    }
    else if (8 <= t && t < 9){
        score = 2;
    }
    else if (9 <= t && t < 10){
        score = 1;
    }
     else if (t >= 10){
        score = 0;
    }
    return score;
}




