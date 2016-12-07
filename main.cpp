/////////////////////////////////////////////////////////////////////////////
// Authored by Jeong-Mo Hong for CSE4060 course at Dongguk University CSE  //
// jeongmo.hong@gmail.com                                                  //
// Do whatever you want license.                                           //
/////////////////////////////////////////////////////////////////////////////

#include <iostream>

#include "NeuralNetwork.h"



void main()
{
	int count = 2;
	VectorND<VectorND<D>> x_input(4);
	x_input[0].initialize(2);
	x_input[1].initialize(2);
	x_input[2].initialize(2);
	x_input[3].initialize(2);
	
	x_input[0][0] = 0.0; x_input[0][1] = 0.0;
	x_input[1][0] = 0.0; x_input[1][1] = 1.0;
	x_input[2][0] = 1.0; x_input[2][1] = 0.0;
	x_input[3][0] = 1.0; x_input[3][1] = 1.0;


	VectorND<VectorND<D>> y_target(4);
	y_target[0].initialize(1);
	y_target[1].initialize(1);
	y_target[2].initialize(1);
	y_target[3].initialize(1);

	y_target[0][0] = 0.0;
	y_target[1][0] = 1.0;
	y_target[2][0] = 1.0;
	y_target[3][0] = 0.0;

	//y_target_array.initialize(2);
	//y_target_array[0].initialize(2);
	//y_target_array[0][0] = 0.1f;
	//y_target_array[0][1] = 0.5f;
	//y_target_array[1].initialize(2);
	//y_target_array[1][0] = 0.8f;
	//y_target_array[1][1] = 0.9f;

	VectorND<D> y_temp(2);

	NeuralNetwork nn_;
	nn_.initialize(2 , 1, 1);
	nn_.alpha_ = 0.1;

	for (int i = 0; i < 400; i++)
		for (int e = 0; e < 4; e++)
	{
		nn_.setInputVector(x_input[e]);
		nn_.propForward();

		nn_.copyOutputVector(y_temp);
		std::cout << x_input[e] << "!!! " << y_target[e]<< "!!! " << y_temp << std::endl;

		nn_.propBackward(y_target[e]);
	}

	//test
	VectorND<VectorND<D>> test(10);
	for (int i = 0; i < 10; i++)
	{
		test[i].initialize(2);
		test[i][0] = 1.0 * i + 10; test[i][1] = 1.0 * i ;
	}
	/*test[0][0] = 0.5; test[0][1] = 0.5;
	test[1][0] = 0.7; test[1][1] = 0.8;
	test[2][0] = 0.8; test[2][1] = 0.7;
	test[3][0] = 0.2; test[3][1] = 0.2;
*/

	for (int e = 0; e < 10; e++)
	{
		std::cout << "test"<< e <<" " << test[e][0]<< ","  << test[e][1] << std::endl;

		nn_.setInputVector(test[e]);
		nn_.propForward();
		nn_.copyOutputVector(y_temp);
		std::cout << y_temp << std::endl;
		std::cout <<""<<std::endl;
	}


}