#include <iostream>
using namespace std;

#define MAX2(a,b) (a) > (b) ? (a) : (b)

class Neuron
{
public:
	Neuron()
		:w_(2.0), b_(1.0)
	{}

	Neuron(const double& w_input, const double& b_input)
		:w_(w_input), b_(b_input)
	{}

public:
	double w_;
	double b_;

	double input_, output_;

	double feedForward(const double& _input)
	{
		input_ = _input;

		const double sigma = w_ * input_ + b_;
		output_ = getAct(sigma);

		return output_;
	}

	void feedForwardAndPrint(const double& input)
	{
		cout << "Input= " << input << " " << feedForward(input) << endl;
	}

	double getAct(const double& x)
	{
		return x; //for linear of identity activation fuctions

		//for ReLU activation fuctions
		//return Max2(0.0, x);
	}

	void propBackward(const double& target)
	{
		double alpha = 0.1; //learning rate

		double grad = (output_ - target) * getActGrad(output_);

		w_ -= alpha * grad * input_; // a*(y-y_target)*grad*1*x
		b_ -= alpha * grad * 1.0; // a*(y-(y_target)*grad*1*1

	}

	double getActGrad(const double& x)
	{
		return 1.0; //for linear of identity activation functions

		//ReLU if(x>0.0) return 1.0; else 0.0;
	}
};

int main()
{
	Neuron my_neuron(2.0, 1.0);

	for (int i = 0; i <= 100; i++)
	{
		cout << "Training " << i << endl;
		my_neuron.feedForwardAndPrint(1.0);
		my_neuron.propBackward(4.0);
		cout << "w= " << my_neuron.w_ << "b= " << my_neuron.b_ << endl;
	}

	return 0;
}