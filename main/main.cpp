#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <cctype>


class Quiz {
public:
    std::string quizName;
    std::vector<std::string> questions;
    std::vector<std::vector<std::string>> answers;
    std::vector<std::string> correctAnswers;
    int score;
    std::vector<bool> usedQuestions;
    std::vector<std::pair<std::string, std::string>> correctQuestions;
    int random = 0;

    void play(){
        std::srand(time(NULL)); // seed rand() with current timestamp

        int score = 0;
        std::vector<std::pair<std::string, std::string>> correctQuestions;
        std::vector<bool> usedQuestions;
        for (auto i : questions) {
            usedQuestions.push_back(false);
        }

        // run as many quiz rounds as there as questions
        for (auto i : questions) {
            while (true) {
                // generate random int within range of 'questions' array
                random = std::rand() % questions.size();
                if (!usedQuestions[random]) { break; }
            }

            // output question and list of answers
            std::cout << questions[random] << std::endl;
            std::cout << "[1] " << answers[random][0] << "    [2] " << answers[random][1] << "    [3] " << answers[random][2] << "    [4] " << answers[random][3] << "\nAnswer: ";

            // take answer from user
            int answer = -1;
            std::cin >> answer;
            if (answers[random][answer - 1] == correctAnswers[random]) {
                std::cout << "Correct!" << std::endl;
                score += 1; // increment score if answer correct
                correctQuestions.push_back(std::make_pair(questions[random], correctAnswers[random])); // add question to list of correct questions
            }
            else {
                std::cout << "Incorrect!" << std::endl;
            }

            usedQuestions[random] = true; // flag question as used
            std::cout << std::endl; // output newline at end of quiz round
        }

        // output final score out of total number of questions
        std::cout << "Your score is " << score << " out of " << questions.size() << "!\n\n";
        std::cout << "You got the following questions correct:\n\n";
        for (int i = 0; i < correctQuestions.size(); i++) {
            std::cout << correctQuestions[i].first << " Answer: " << correctQuestions[i].second << std::endl;
        }
    }
    Quiz(std::string name) : quizName(name){};
};

int main()
{
    // create quizData object
    Quiz quiz("General Knowledge");
    // set questions
    quiz.questions.push_back("What is the capital of France? ");
    quiz.questions.push_back("What planet is closest to the sun? ");
    quiz.questions.push_back("What is the answer to life, the universe and everything? ");
    quiz.questions.push_back("What is the capital of Spain? ");
    quiz.questions.push_back("What programming language is this program written in? ");
    // set potential answers
    quiz.answers.push_back({ "London", "Paris", "Berlin", "Madrid" });
    quiz.answers.push_back({ "Earth", "Jupiter", "Neptune", "Mercury" });
    quiz.answers.push_back({ "42", "69", "4", "0" });
    quiz.answers.push_back({ "Barcelona", "Madrid", "Valencia", "Seville" });
    quiz.answers.push_back({ "Python", "Java", "C++", "Lua" });
    // set correct answers
    quiz.correctAnswers.push_back("Paris");
    quiz.correctAnswers.push_back("Mercury");
    quiz.correctAnswers.push_back("42");
    quiz.correctAnswers.push_back("Madrid");
    quiz.correctAnswers.push_back("C++");

    // play quiz
    std::string endQuiz = "";
    do {
        endQuiz = "";
        quiz.play();
        while (endQuiz != "N" && endQuiz != "Y") {
            std::cout << "\nWould you like to play again?\n[Y] Yes\n[N] No\n";
            std::cin >> endQuiz;
            for (char& c : endQuiz) { c = toupper(c); } // cast 'endQuiz' to upper
        }
    } while (endQuiz != "N");
    return 0;
}

