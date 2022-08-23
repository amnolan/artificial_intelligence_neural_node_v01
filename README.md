# artificial_intelligence_neural_node
Artificial Intelligence Neural Node

This is a project I did in college years ago which I very much enjoyed. It is an aritifical intelligence neural node (perceptron) which follows the traditional formula for progressively improving the perceptron's guess on what the correct response should be.

# how it works

At a high level, the way it works is you give the perceptron a piece of data, it outputs "True" or "False", then you (or
some data set) gives it a "True" or "False" to answer whether the "guess" of the perceptron is correct. If it is correct, you
do nothing, otherwise you increment a weight on that particular perceptron index. This continues until the "guesses" produced by the formula are consistently correct.

The concept may seem intimidating at first but upon reading through the purpose you'll find that it's actually pretty straight forward. I highly advise reading about it http://computing.dcu.ie/~humphrys/Notes/Neural/single.neural.html before attempting to understand what
this code is doing as it will be very abstract without context.

At a lower level, this program is set up to take in a file of variable length, with 16 characters comma separated followed by a programmed response (either 1 or 0). We feed these data points in and allow the logic to run. What is this particular data set designed to do you ask?

We are training the perceptron to recognize upper case letters versus lower case letters through training. This perceptron was able to recognize with 92% accuracy. By "pre-weighting" the weights you can sort of cheat and get a better accuracy, near to 99%. To do this, you would run it first and figure out the weights and then hard code the starting weights. You could also modify the code to read in the starting weights.

The cool thing is, you can really use this node for any data points which have 16 bit inputs, it doesn't have to be for ASCII. You can even "layer" this with several other nodes and create an actual network to recognize progressively more complex objects.

To compile and run: Assuming you're using GCC:
    
    #compile and build the executable on a *nix machine, for windows it should be the same, except the prompt of $ becomes > 
    $gcc -o artificial_neural_node.exe artificial_neural_node.c
    
    #run the executable on a *nix machine (windows you drop the ./)
    $./artificial_neural_node.exe

![Perceptron Screenshot](https://github.com/amnolan/artificial_intelligence_neural_node_v01/raw/master/perceptron_screenshot.png?)
