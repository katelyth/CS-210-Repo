# Airgead Banking Interest Calculator

# Summarize the project and what problem it was solving.
This project was to create an interest calculator for the client, Airgead banking. They were looking for a product that would calculate annual interest that compounded monthly and output the total, with the user defining the interest rate, monthly deposit, and initial deposit.

# What did you do particularly well?
I think one of the best things I did was wrapping all of the main functionality of the code in functions. My goal was to keep the least amount of code possible in main(). There is effectively no actual defined functionality in Main() besides initializing the variables and running the program in a While loop. 

# Where could you enhance your code? How would these improvements make your code more efficient, secure, and so on?
I think ensuring the proper functions are put under the proper public/private settings would help the code be more secure. As it is, all the functions are public, meaning they can be called from Main() and cause the program not to run as it should. By putting some of the functions as private functions and only allowing them to be called by the functions that need them, the code would be more efficient and far more secure. 

# Which pieces of the code did you find most challenging to write, and how did you overcome this? What tools or resources are you adding to your support network?
The hardest part of this code was making sure the math worked properly. Interest is a fairly straightforward calculation, but when it came to calculating the year-end value with monthly deposits, it was somewhat confusing at first to make sure the loops were set up correctly. After I thought I'd had it right, I realized I didn't zero out the interest at the beginning of each year, which was causing the interest to calculate more than it should and throwing off the whole calculation. It was a mixture of googling how to calculate interest rates, as well as discussing the project with other classmates that helped overcome. 

# What skills from this project will be particularly transferable to other projects or course work?
Making sure the code is easily readable is a big transferable skill. Additionally, taking real life math and putting it into a code project was very helpful to see how I can take a real-life problem and solve it with code. 

# How did you make this program maintainable, readable, and adaptable?
By including comments throughout the code, as well as wrapping all the main functionality of the project in functions, this code is very easy to read and very easy to expand upon. Most of the code is kept outside of Main(), so adding additional functions does not mess up the program and how it works. 
