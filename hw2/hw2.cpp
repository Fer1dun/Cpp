#include <iostream>
#include <string>
#include <vector>
#include <fstream>
class file{
private:
	int width,height,maxval;
	std::string line;
public:
	//constructor 
	file(){
		width=0;
		height=0;
		maxval=0;
		line="empty";

}
	std::vector<std::vector<int>> pixels;
	//getting color information from the file
	std::vector<std::vector<int>> myvector(std::string name){
		std::ifstream file(name);
	    if(file.is_open()){
	    	file >> line >> width >> height >> maxval;
		    for (int i = 0; i < height; i++) {
		        std::vector<int> row;
		        for (int j = 0; j < width; j++) {
		            int r, g, b;
		            file >> r >> g >> b;
		            row.push_back(r);
		            row.push_back(g);
		            row.push_back(b);
		        }
		        pixels.push_back(row);
		    }
		    file.close();}
		    else{
		    	std::cout<<"File not found"<<std::endl;
	    }
	    return pixels;
	}

	//writes new colors to file
	void out_file(std::string filename) {
	    std::ofstream file(filename);
	    file << line<<" \n" << width << " " << height << "\n" << maxval << "\n";
	    for (int i = 0; i < height; i++) {
	        for (int j = 0; j < width; j++) {
	            int r = pixels[i][j*3];
	            int g = pixels[i][j*3+1];
	            int b = pixels[i][j*3+2];
	            file << r << " " << g << " " << b << " ";
	        }
	        file << "\n";
	    }
	    file.close();
}
	//adjusts the numbers inside the vector to the new numbers
	void Scripts (float c_r, float c_g, float c_b) {
	    for (auto &	row : pixels) {
	        for (int i = 0; i < row.size(); i += 3) {
		            int r = c_r * row[i] + c_g * row[i+1] + c_b * row[i+2];
		            int g = c_r * row[i] + c_g * row[i+1] + c_b * row[i+2];
		            int b = c_r * row[i] + c_g * row[i+1] + c_b * row[i+2];
		            if (r > 255) r = 255;
		            if (g > 255) g = 255;
		            if (b > 255) b = 255;
		            row[i] = r;
		            row[i+1] = g;
		            row[i+2] = b;
        }
    }
}
};

int main(int argc, char const *argv[])
{
	file read_file;
	int exit=-1,exit2=-1,exit3=-1;
	std::string file_name;
	std::vector<std::vector<int>> realvector;
	while(exit!=0){
	std::cout<<"0 - Exit"<<std::endl;
	std::cout<<"1 - Open An Image(D)"<<std::endl;
	std::cout<<"2 - Save An Image(D)"<<std::endl;
	std::cout<<"3 - Scripts(D)"<<std::endl;
	std::cin>>exit;

	if(exit==1){
		std::cout<<"0 - Up"<<std::endl;
		std::cout<<"1- Enter The Name Of The Image File"<<std::endl;
		std::cin>>exit2;
		if(exit2==1){
			std::cin>>file_name;
			realvector=read_file.myvector(file_name);

		}
		else if(std::cin.fail()){
			std::cin.clear();
			std::cout<<"wrong"<<std::endl;
		}

	}
	else if(exit==2){
		std::cout<<"0 - Up"<<std::endl;
		std::cout<<"1- Enter The File Name"<<std::endl;
		std::cin>>exit2;
		if(exit2==1){
			//check vector empty or full
			if(realvector.empty()==1){
				std::cout<<"vector is empty"<<std::endl;
			}
			else{
			std::cin>>file_name;
			read_file.out_file(file_name);
		}
	}	//
		else if(std::cin.fail()){
			std::cin.clear();
			std::cout<<"wrong"<<std::endl;
		}
	}
	else if(exit==3){
		std::cout<<"0 - Up"<<std::endl;
		std::cout<<"1 - Convert To Grayscale(D)"<<std::endl;
		std::cin>>exit2;
		  if(exit2==1){
		  	std::cout<<"0 - Up"<<std::endl;
		  	std::cout<<"1 - Enter Coefficients For RED GREEN And BLUE Channels."<<std::endl;
		  	std::cin>>exit3;
			  	if(exit3==1){
			  		////check vector empty or full
			  		if(realvector.empty()==1){
					std::cout<<"vector is empty"<<std::endl;}
					else{
						while(true){
			  		float c_b,c_g,c_r;
			  		std::cin>>c_r>>c_g>>c_b;
			  		if((c_r<1 && c_r>=0) && (c_b<1 && c_b>=0) && (c_g<1 && c_g>=0)){
			  		read_file.Scripts(c_r,c_g,c_b);
			  		break;
			  	}
			  	else std::cout<<" not valid number \n again "<<std::endl;
			  	}
			  }
			  }
			  else if(std::cin.fail()){
				std::cin.clear();
				std::cout<<"wrong"<<std::endl;
			}
		  }
		  else if(std::cin.fail()){
			std::cin.clear();
			std::cout<<"wrong"<<std::endl;
		}
	}

}
	return 0;
}