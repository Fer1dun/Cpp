#include <iostream>
#include <fstream>
#include <vector>
#include <string>


int test_print(const std::string filename_image1);
class ppm_image{
private:
	 int width,height,maxval;
	 std::string line;
	 
public:
	std::vector<std::vector<int>> pixels;
	int get_widht() const {
		return width;
	}
	int get_maxval() const{
		return maxval;
	}
	std::string get_line() const {
		return line;

	}
	int get_height() const {
		return height;
	}
	ppm_image();
	ppm_image(std::string name);
	ppm_image(int width,int height,std::string line,int Maxval);
	int myvector(std::string name);
	int out_file(std::string filename) const ;
	friend std::ostream & operator<<(std::ostream & os,const ppm_image& image1);
	//it overload + operator
	ppm_image  operator+(ppm_image  &other){
    ppm_image new_image ;
    new_image.width = other.width;
    new_image.height = other.height;
    new_image.line = other.line;
    new_image.maxval = other.maxval;
    for(int i=0; i<width; i++){
   		std::vector<int> new_pixel;
        for(int j=0; j<height; j++){
            for(int k=0; k<3; k++){
                int sum = pixels[i][j*3 + k] +other.pixels[i][j*3 + k];
                if(sum >= 255)
                    sum = 255;
                if(sum <= 0)
                    sum = 0;
                new_pixel.push_back(sum);
            }					
         }
         new_image.pixels.push_back(new_pixel);   
    } 
    return new_image;
}
	int & operator()(int row, int col, int channel)  {
    return pixels[row][col * 3 + channel - 1];

}
//it overloads - operator
	ppm_image operator-(ppm_image const & other){
    ppm_image new_image;
    new_image.width = width; 
    new_image.height = height; 
    new_image.line = line; 
    new_image.maxval = maxval;
    for(int i=0; i<4; i++){
    	std::vector<int> new_pixel;
        for(int j=0; j<4; j++){ 
            for(int k=0; k<3; k++){
            	int sub=pixels[i][j*3 + k] - other.pixels[i][j*3 + k];
            	if(sub>255)
            		sub=255;
            	if(sub<0)
            		sub=0;
                new_pixel.push_back(sub);
            }
        }
        new_image.pixels.push_back(new_pixel);
    }
    return new_image;
}
};
//it overload print founction
std::ostream& operator<<(std::ostream& os, const ppm_image& image1){
    for (const auto& row : image1.pixels){
    	std::cout<<row.size()<<std::endl;
        for (int i=0; i<row.size(); ++i){
            os << row[i] << " ";
        }
        os << std::endl;
    }
    return os;
}
//based constructor
ppm_image::ppm_image(){
	width=0;
	height=0;
	maxval=0;
	line="empy";
}
//constructor takes one argumnet and sets the vector size
ppm_image::ppm_image(std::string name){
	std::ifstream File(name);
	if(!File.is_open()) {
                std::cerr << "Error: could not open file\n";
                return;
            }
     File>>line>>width>>height>>maxval;
     pixels.resize(height);
            for (auto& row : pixels) {
                row.resize(width);
            }
     File.close();

}
//constructor takes 4 argument
ppm_image::ppm_image(int Width,int Height,std::string name,int Maxval){
	width=Width;
	height=Height;
	maxval=Maxval;
	line=name;
	pixels.resize(height, std::vector<int>(width*3));
	for (int row = 0; row < height; row++) {
            for (int col = 0; col < width*3; col++) {
                pixels[row][col] = 255;
            }
        }
}
//it writes to file
int ppm_image::out_file(std::string filename) const {
	    std::ofstream file(filename);
	    if(file.is_open()){
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
	    file.close();}
	    else { 
	    	return 0;}



	    return 1;
}
//it reads from file
int ppm_image::myvector(std::string name){
		std::ifstream file(name);
	    if(file.is_open()){
	    	file >> line >> width >> height >> maxval;
		    for (int i = 0; i < 4; i++) {
		        std::vector<int> row;
		        for (int j = 0; j < 4; j++) {
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
		    	return 0;
	    }
	    return 1;
	}
//it reads from file
int read_ppm(const std::string source_ppm_file_name, ppm_image& destination_object){
	int control;
	std::string name=source_ppm_file_name;
	control=destination_object.myvector(name);
	if(control==0){
		return 0;
	}

	return 1;

}
//it reads to file
int write_ppm(const std::string destination_ppm_file_name, const ppm_image& source_object){
	int control;
	std::string name=destination_ppm_file_name;
	control=source_object.out_file(name);
	if(control==0){
		return 0;

	}


	return 1;
}
//it add two class
int test_addition(const std::string filename_image1, const std::string filename_image2, const std::string filename_image3){
	int control1,control2,control3;
	ppm_image image1;
	ppm_image image2;
	ppm_image image3;
	control1=read_ppm(filename_image1,image1);
	control2=read_ppm(filename_image2,image2);
	image3=image1+image2;
	control3=write_ppm(filename_image3,image3);
	if(control1==0 || control2==0 || control3==0)
		return 0;
	return 1;
}
int test_print(const std::string filename_image1){
	ppm_image image1;
	read_ppm(filename_image1,image1);
	std::cout<<image1;
	return 1;
}
//it subtract two class
int test_subtraction(const std::string filename_image1, const std::string filename_image2, const std::string filename_image3){
	int control1,control2,control3;
	ppm_image image1;
	ppm_image image2;
	ppm_image image3;
	control1=read_ppm(filename_image1,image1);
	control2=read_ppm(filename_image2,image2);
	image3=image1-image2;
	control3=write_ppm(filename_image3,image3);
	if(control1==0 || control2==0 || control3==0)
		return 0;
	

	return 1;

}
//swap two different colors with each other
int swap_channels(ppm_image& image_object_to_be_modified, int choice){
	for (auto &	row : image_object_to_be_modified.pixels) {
	        for (int i = 0; i < row.size(); i += 3) {
	        	if(choice==2){
		            int r = row[i+2];
		            int b = row[i];
		            row[i] = r;
		            row[i+2] = b;}
		            else if(choice==3){
		            	int g=row[i+2];
		            	int b=row[i+1];
		            	row[i+1]=g;
		            	row[i+2]=b;

		            }
		            else if(choice==1){
		            	int r=row[i+1];
		            	int g=row[i];
		            	row[i]=r;
		            	row[i+1]=g;

		            }
        }
    }
return 1;

}
//adjusts colors based on entered data
ppm_image single_color(ppm_image& source, int color_choice){
	int  width=source.get_widht();
	int  height=source.get_height();
	std::string line=source.get_line();
	int maxval=source.get_maxval();
	ppm_image copy_image(width,height,line,maxval);
    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height; ++j) {
            for (int k = 1; k <= 3; ++k) {
                if (k == color_choice) {
                    copy_image(i, j, k) = source(i, j, k);
                } else {
                    copy_image(i, j, k) = 0;
                }
            }
        }
    }
return copy_image;


}
 int main(int argc, char *argv[]){
	int choice=atoi(argv[1]);
	std::string name = argv[2];
	std::string name2 = (argc > 3) ? argv[3] : "";
	std::string name3 = (argc > 4) ? argv[4] : "";
	ppm_image image1;
	ppm_image image2;
	if(choice==1){
		if(!name2.empty() && !name3.empty())
			test_addition(name,name2,name3);

	}
	else if(choice==2){
		if(!name2.empty() && !name3.empty())
			test_subtraction(name,name2,name3);	
	}
	else if(choice==3){
		read_ppm(name,image1);
		swap_channels(image1,1);
		write_ppm("ppm_file_name2",image1);
	}
	else if(choice==4){
		read_ppm(name,image1);
		swap_channels(image1,2);
		write_ppm("ppm_file_name2",image1);

	}
	else if(choice==5){
		read_ppm(name,image1);
		image2=single_color(image1,1);
		write_ppm("ppm_file_name2",image2);
	}
	else if(choice==6){
		read_ppm(name,image1);
		image2=single_color(image1,2);
		write_ppm("ppm_file_name2",image2);
	}
	else if(choice==7){
		read_ppm(name,image1);
		image2=single_color(image1,3);
		write_ppm("ppm_file_name2",image2);
	}

	return 0;
}

