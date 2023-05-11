// Automated Grader 
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

//function prototypes
void print_header();
void print_footer(double average);
void print_student(const string &student, int score);
int process_response(const string &response, const string &answer_key);

void print_header()
{
    cout << setw(15) << left << "Student" << setw(5) << "Score" << endl;
    cout << setw(20) << setfill('-') << "" << endl;
    cout << setfill(' ');  
}

void print_footer(double average) 
{
    cout << setw(20) << setfill('-') << "" << endl;
    cout << setfill(' ');  
    cout << setw(15) << left << "Average score" << setw(5) << right << average;
}

void print_student(const string &student, int score) 
{
    cout << setprecision(1) << fixed;
    cout << setw(15) << left << student << setw(5) << right << score << endl;
}

// return the number of correct responses
int process_response(const string &response, const string &answer_key) 
{
    int score {0};
    for (size_t i = 0; i < answer_key.size() ; ++i) 
    {
        if (response.at(i)  == answer_key.at(i))
            score++;
    }
    return score;
}

int main() 
{
    ifstream in_file;
    string answer_key {};
    string name {};
    string response{};
    int running_sum {0};
    int total_students {0};
    double average_score {0.0};
    
    in_file.open("./responses.txt");
    if (!in_file) 
    {
        cerr << "Problem opening file" << endl;
        return 1;
    }
    
    in_file >> answer_key;
    
    print_header();
    
    while (in_file >> name >> response) 
    {
        ++total_students;
        int score = process_response(response, answer_key);
        running_sum += score;
        print_student(name, score);
    }

    if (total_students != 0)
        average_score = static_cast<double>(running_sum)/total_students;
        
    print_footer(average_score);
    
    in_file.close();
    cout << endl << endl;

    return 0;
}