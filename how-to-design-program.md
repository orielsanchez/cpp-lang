# Design Steps
## 1. Define Your Goal
- Define goal in 1-2 sentences
- User-facing outcome
- Examples:
    - Allow user to organize a list of names and associated phone numbers
    - Generate list of stock recommendations
    - Generate randomized dungeon
    - Model how long a ball dropped off a tower takes to hit ground

## 2. Define Requirements
- List constraints, e.g. budget, timeline, space, memory
- What 'SHOULD' the program do?
- solution isn't done until all requirements are met

## 3. Define your tools, targets, and backup plan
- Define what target architecure and/or OS your program will run on
- Determine what set of tools you will be using
- Determine whether you will write program alone or part of a team
- Defining your testing/feedback/release strategy
- Determining how you will back up your code
- As a new programmer, answers are simple:
    - For own use, alone, on own system, using nvim/g++, code not used by anybody but me.

## 4. Break hard problems down into easy problems
- Top down method of problem solving
- task hierarchies define structure of program
    - top level task becomes main
    - subitems become functions in the program
- If one of the items is too difficult to implement, simply split that item into multiple sub-items/sub-functions.
    - Eventually you should reach a point where each function in your program is trivial to implement.

## 5. Figure out the sequence of events
- Example (Calculator):
    - get first number from user
    - get math operator from user
    - get second number from user
    - calculate result
    - print result

# Implementation Steps
## 6. Outlining your main function
- Create functions stubs from sequence of events
- Don't worry about inputs/outputs yet

## 7. Implement each function
- For each function:
    - Define the function prototype (inputs and outputs)
    - Write a function
    - Test the function
- If your functions are granular enough, each function should be fairly simple and straightforward.
- Overly-complex to implement? Break down into subfunctions that can be more easily implemented.

- Remember: Don't implement your entire program in one go. WOrk in steps, testing each step along the way before proceeding.

## 8. Final Testing
- Test whole program to ensure it words as intended.
- Debug!

# Words of advice when writing programs
## Keep your programs simple to start
- Often new programmers have a grand vision for all the things they want their program to do.
    - If you try to write something too complex to start, you will become overwhelmed and discouraged at your lack of progress.
- Instead, make your first goal as simple as possible, something that is definitely within your reach.
    - For example, “I want to be able to display a 2-dimensional field on the screen”.

## Add features over time.
- Once you have your simple program working and working well, then you can add features to it.
    - For example, once you can display your field, add a character who can walk around.
    - Once you can walk around, add walls that can impede your progress.
    - Once you have walls, build a simple town out of them.
    - Once you have a town, add merchants.
- By adding each feature incrementally your program will get progressively more complex without overwhelming you in the process.

## Focus on one area at a time.
- Don’t try to code everything at once, and don’t divide your attention across multiple tasks.
- Focus on one task at a time.
- It is much better to have one working task and five that haven’t been started yet than six partially-working tasks.
- If you split your attention, you are more likely to make mistakes and forget important details.

## Test each piece of code as you go.
- New programmers will often write the entire program in one pass.
    - Then when they compile it for the first time, the compiler reports hundreds of errors.
    - This can not only be intimidating, if your code doesn’t work, it may be hard to figure out why.
    - Instead, write a piece of code, and then compile and test it immediately.
    - If it doesn’t work, you’ll know exactly where the problem is, and it will be easy to fix.
- Once you are sure that the code works, move to the next piece and repeat.
    - It may take longer to finish writing your code, but when you are done the whole thing should work
    - You won’t have to spend twice as long trying to figure out why it doesn’t.

## Don’t invest in perfecting early code.
- The first draft of a feature (or program) is rarely good.
- Furthermore, programs tend to evolve over time, as you add capabilities and find better ways to structure things.
- If you invest too early in polishing your code, you risk losing all of that investment when a code change is necessary.
    - E.g. adding lots of documentation, full compliance with best practices, making optimizations
- Instead, get your features minimally working and then move on.
    - As you gain confidence in your solutions, apply successive layers of polish.
- Don’t aim for perfect -- non-trivial programs are never perfect, and there’s always something more that could be done to improve them.
- Get to “good enough” and move on.

## Optimize for maintainability, not performance.
- There is a famous quote (by Donald Knuth) that says “premature optimization is the root of all evil”.
- New programmers often spend far too much time thinking about how to micro-optimize their code 
    - e.g. trying to figure out which of 2 statements is faster
    - This rarely matters.
- Most performance benefits come from: 
    - good program structure,
    - using the right tools and capabilities for the problem at hand, and
    - following best practices.
- Additional time should be used to improve the maintainability of your code.
    - Find redundancy and remove it.
    - Split up long functions into shorter ones.
    - Replace awkward or hard to use code with something better.
- The end result will be code that is easier to improve and optimize later and fewer bugs
    - after you’ve determined where optimization is actually needed 

