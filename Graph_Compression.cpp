#include <bits/stdc++.h>
using namespace std;

// A Huffman tree node
struct MinHeapNode {

	// One of the input characters
	int data;
	
	// Frequency of the character
	unsigned freq;

	// Left and right child
	MinHeapNode *left, *right;

	MinHeapNode(int data, unsigned freq){
		left = right = NULL;
		this->data = data;
		this->freq = freq;
	}
};

// For comparison of two heap nodes (needed in min heap)
struct compare {
	bool operator()(MinHeapNode* l, MinHeapNode* r){
	return (l->freq > r->freq);
	}
};

vector<pair<int,string>> vs;
int variableEncodingCost,huffmanNode;

// Prints huffman codes from the root of Huffman Tree.
void printCodes(struct MinHeapNode* root, string str){
	if (!root)
	return;
	if (root->data !=-1){
	//cout<< root->data << ":          " << str << "\n";
	vs.push_back({root->data,str});
	variableEncodingCost+=str.length();
	}
	printCodes(root->left, str + "0");
	printCodes(root->right, str + "1");
}

void HuffmanCodes(int data[], int freq[], int size)
{
	struct MinHeapNode *left, *right, *top;

	priority_queue<MinHeapNode*, vector<MinHeapNode*>,
				compare>
		minHeap;

	for (int i = 0; i < size; ++i)
		minHeap.push(new MinHeapNode(data[i], freq[i]));
    huffmanNode=size;
	while (minHeap.size() != 1) {
		left = minHeap.top();
		minHeap.pop();
		right = minHeap.top();
		minHeap.pop();
		top = new MinHeapNode(-1,left->freq + right->freq);
		huffmanNode++;
		top->left = left;
		top->right = right;
		minHeap.push(top);
	}
	// Print Huffman codes using the Huffman tree built above
	//cout<<"\nThe variable length code for each node is:-\n";
	
	printCodes(minHeap.top(), "");
}

void takeInput(int &x,int &y){
string s1,s2;
int flag=1;
     cin>>s1>>s2;
    for(int i=1;i<s1.length()-1;i++){
    x=(x*10)+(s1[i]-'0');		
	}
	for(int i=0;i<s2.length()-1;i++){
    y=(y*10)+(s2[i]-'0');		
	}
}

double calculate_mean(int data[],int n) {
    double sum = 0;
    for (int i=0;i<n;i++) {
        sum += data[i];
    }
    return sum /n;
}

double calculate_standard_deviation(int data[],int n) {
    const double mean = calculate_mean(data,n);
	
    double squared_difference_sum = 0;
    for (int i=0;i<n;i++) {
		double element=data[i];
        squared_difference_sum += std::pow(element - mean, 2);
    }
    const double variance = squared_difference_sum /(n-1);
    return std::sqrt(variance);
}

int main()
{
    int nodes=0,edges=0;
	//cout<<"Enter the total nodes and edges\n";
    
	freopen("input20.txt", "r", stdin);
	freopen("output20.txt", "w", stdout);
    
    takeInput(nodes,edges);

	cout<<"Nodes: "<<nodes<<"\n";
	vector<int> adj[nodes];
    int freq[nodes];
    memset(freq,0,sizeof(freq));
	//cout<<"Enter the edges\n";
    cout<<"edges: "<<edges<<"\n";
	double dl=1;
	double density=((dl)*edges/(nodes*(nodes-1)/2));
	cout<<"Density: "<<density<<"\n";
	
	for(int i=0;i<edges;i++){
     int x=0,y=0;
	 takeInput(x,y);
     freq[x]++;
     freq[y]++;
	 adj[x].push_back(y);
	 adj[y].push_back(x);
    }
    int arr[nodes];
    for(int i=0;i<nodes;i++){
    arr[i]=i;		
	}

	variableEncodingCost=0;
	huffmanNode=0;
	HuffmanCodes(arr, freq,nodes);
    int bits=0,number=1;
	// Calculation of Bits for fixed length coding
    while(number<nodes){
    bits++;
	number*=2;
	}
	
    sort(vs.begin(),vs.end());

    // Calculation of bits for Huffman Tree 
	int huffmanEdge=2*(huffmanNode-nodes); 
	
    // Calculation of bits by assuming fixed length coding 
	int fixedEncodingCost=(bits*(nodes+2*edges));
	cout<<"Total bits in fixed length coding "<<fixedEncodingCost<<"\n";
	
	// Calculation of bits by assuming variable length coding for edges
    for (int i = 0; i < nodes;i++) {
    for (auto it : adj[i]){
    variableEncodingCost+=(vs[it].second).length();
	}     
    }



	int huffmanEncodingbit=(bits*(huffmanNode+(2*huffmanEdge)));
    cout<<"Total bits in Huffman tree coding "<<huffmanEncodingbit<<"\n";
	cout<<"Compressed Ratio without HuffmanTree: "<<((double)variableEncodingCost/fixedEncodingCost)<<"\n";
   
	variableEncodingCost+=huffmanEncodingbit;  // for huffman Tree
	cout<<"Total bits in variable length coding "<<variableEncodingCost<<"\n";
	
	// Calculation of efficientcy
	cout<<"The efficientcy of the this Graph compression algorithm is "<<((double)(dl*fixedEncodingCost-variableEncodingCost)/fixedEncodingCost)*100<<"%\n";
	
    cout<<"Compressed Ratio: "<<((double)variableEncodingCost/fixedEncodingCost)<<"\n";
    
	cout<<"Encoding cost of Total bits in Huffman tree coding / total bits in variable length coding "<<(double)(dl*huffmanEncodingbit/variableEncodingCost)*100<<"%\n";
    
	int minFreq=INT_MAX,maxFreq=0;
	for(int i=0;i<nodes;i++){
    minFreq=min(minFreq,freq[i]);
	maxFreq=max(maxFreq,freq[i]);		
	}
	//The range tells us the difference between the largest and smallest value in the entire dataset. 
    cout<<"Minimum Frequency: "<<minFreq<<" Maximum Frequency: "<<maxFreq<<"\n";
	
    cout<<"Mean: "<<calculate_mean(freq,nodes)<<" ";
    //The standard deviation tells us the typical deviation of individual values from the mean value in the dataset.
	cout << "Standard deviation: " << calculate_standard_deviation(freq,nodes) << '\n';
    

	cout<<"Node    Variable length code\n";
	for(int i=0;i<vs.size();i++){
    cout<<vs[i].first<<"       "<<vs[i].second<<"\n";		
	}
	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}

