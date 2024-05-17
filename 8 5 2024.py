#!/usr/bin/env python
# coding: utf-8

# # Theme:Down Memory Lane

# In[2]:


from IPython.display import HTML, display
import random

class TableTopics:
    def __init__(self):
        self.questions = {}
        self.load_questions()  # Load questions into the dictionary
    
    def load_questions(self):
        # Load questions from a file or define them directly here
        # Format: {question_number: (question_text, answered_status)}
        self.questions = {
            1: ("What is your hobby when you are young, are your parents supportive", False),
            2: ("Recall your first time you left your home country", False),
            3: ("What is the earliest point in your life that you can recall?", False),
            4: ("How did your parents influence you to be who you are today?", False),
            5: ("How have your relationship with your parents evolved?", False),
            6: ("Was there any disagreement between you and your parents", False),
            7: ("Was there any valuable lessons from your parents", False),
            8: ("Did you feel your parents support you sufficiently", False),
            9: ("Parents were the only ones obligated to love you; from the rest of the world you had to earn it. - Ann Brashares", False),
            10: ("How important are your parents to you?", False),
            11: ("How did your parents discipline you when you are young", False),
            12: ("What is your fondest childhood memory", False),
            # Add more questions as needed
        }
    
    def get_question(self, number):
        if number in self.questions and not self.questions[number][1]:
            return self.questions[number][0]
        else:
            return "Question already answered or not found."
    
    def get_random_unanswered_question(self):
        unanswered_questions = [number for number, (question, answered) in self.questions.items() if not answered]
        if unanswered_questions:
            random_number = random.choice(unanswered_questions)
            return self.get_question(random_number)
        else:
            return "All questions have been answered."
    
    def mark_question_answered(self, number):
        if number in self.questions:
            self.questions[number] = (self.questions[number][0], True)
            return "Question marked as answered."
        else:
            return "Question not found."


def table_topics_interface():
    table_topics = TableTopics()
    while True:
        print("")
        print("Welcome to Table Topics!")
        print("Enter a number from 1 to 12 to get a question.")
        print("Enter R to get a random question.")
        print("Enter A to show remaining questions.")
        print("Enter 'q' to quit.")
        choice = input("Your choice: ")
        print("")

        if choice.lower() == 'q':
            print("Goodbye!")
            break
            
        elif choice.upper() == 'A':  # Display all remaining unanswered questions
            unanswered_questions = [number for number, (question, answered) in table_topics.questions.items() if not answered]
            if unanswered_questions:
                print("Remaining Unanswered Questions:")
                for number in unanswered_questions:
                    print(f"<div style='font-size: 20px;'>{number}</div>")
            else:
                print("All questions have been answered.")
    
        elif choice.upper() == 'R':  # Convert choice to uppercase to handle lowercase input as well
            random_number = random.randint(1, 12)
            question = table_topics.get_question(random_number)
            if question != "Question already answered or not found.":
                print(f"<div style='font-size: 60px;'>Random Question ({random_number}): {question}</div>")  # Print the question
                mark_as_answered = input("Mark as answered? (y/n): ")
                if mark_as_answered.lower() == 'y':
                    print(table_topics.mark_question_answered(random_number))
            else:
                print("All questions have been answered.")
            
        
        elif choice.isdigit():
            number = int(choice)
            if 1 <= number <= 12:
                question = table_topics.get_question(number)
                if question != "Question already answered or not found.":
                    print(f"<div style='font-size: 60px;'>Question {number}: {question}</div>")  # Print the question
                    mark_as_answered = input("Mark as answered? (y/n): ")
                    if mark_as_answered.lower() == 'y':
                        print(table_topics.mark_question_answered(number))
                else:
                    print(question)
            else:
                print("Invalid choice. Please enter a number between 1 and 12.")
        else:
            print("Invalid input. Please enter a number or 'q' to quit.")

table_topics_interface()


# In[ ]:




