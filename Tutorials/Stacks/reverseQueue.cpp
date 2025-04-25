void reverseQueue(queue<int> &input) {
	// Write your code here
	if(input.empty())
	  return;
	  int temp=input.front();
	  input.pop();
	reverseQueue(input);
	   input.push(temp);  
}
