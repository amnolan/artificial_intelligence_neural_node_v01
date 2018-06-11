# artificial_intelligence_neural_node
Artificial Intelligence Neural Node

This is a project I did in college years ago which I very much enjoyed. It is an aritifical intelligence neural node (perceptron) which follows the traditional formula for progressively improving the perceptron's guess on what the correct response should be.

# disclaimer

I understand that the code is very procedural. This is intentional and in a world of "OOP is the best," it's sort of silly but people seem to get flustered when they see "non-OOP" code. Especially new developers who have been drinking code boot camp Koolaid (you know who you are). This was my first ever program in C and the subject matter was more about getting the AI perceptron to work, than anything else.

I did consider "decomposing" the logic into functions to make the code neater (but why?). Very few people probably go back to their college projects and rework them. After all, developers love trying new and exciting things. C doesn't fit into that category.

# how it works

At a high level, the way it works is you give the perceptron a piece of data, it outputs "True" or "False", then you (or
some data set) gives it a "True" or "False" to answer whether the "guess" of the perceptron is correct. If it is correct, you
do nothing, otherwise you increment a weight on that particular data point. This continues until the "guesses" produced by the formula are consistently correct.

This seems very intimidating at first but upon reading through the purpose it's actually pretty straight forward. I highly
advise reading about it http://computing.dcu.ie/~humphrys/Notes/Neural/single.neural.html before attempting to understand what
this code is doing as it will be very abstract.

At a lower level, this program is set up to take in a file of variable length, with 16 characters comma separated followed by a programmed response (either 1 or 0). We feed these data points in and allow the logic to run. What is this particular data set designed to do you ask?

We are training the perceptron to recognize upper case letters versus lower case letters. If my memory serves me
correctly this perceptron made it to 92% or 93% accuracy. By "pre-weighting" the weights you can sort of cheat and get a better accuracy, I didn't choose to go that route.

The cool thing is, you can really use this node for any data points which have 16 bit inputs. You can even "layer" this
with several other nodes and create an actual network to recognize progressively more complex objects.

To compile and run with the provided sample data, please check the wiki.

![Perceptron Screenshot](https://github.com/amnolan/artificial_intelligence_neural_node_v01/raw/master/perceptron_screenshot.png?)
