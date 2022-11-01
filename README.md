# Computer Vision Project -- Hough Line Transform - SIFT Features - Harris Corner - BoW Algorithms with OpenCV
[![Software: C++](https://img.shields.io/badge/Software-C%2B%2B-blue)](http://www.cplusplus.org/)  [![Library: OpenCV](https://img.shields.io/badge/Library-OpenCV-green)](https://www.opencv.org/) [![License: MIT](https://img.shields.io/badge/License-MIT-lightgrey)](https://mit-license.org/) 

Developer: Baturay Özgürün

Copyright © 2018 Baturay Özgürün

If you have any requests or questions please do not hesitate to contact me via baturay.ozgurun@gmail.com

---

## Project Description

This project performs 4 algorithms sequentially to extract and present image features; (1) Hough Line Transform, (2) SIFT, (3) Harris Corner, and (4) BoW. The aims of these algorithms are as follows
- The Hough Line Transform detects straight lines in an input image and presents line parameters in a text file.
- The Scale Invariant Feature Transform (SIFT) Algorithm detects local features of an input image and presents 128-dimensional vectors in a text file.
- The Harris Corner Algorithm extracts corners in an input image and presents corner locations in a text file.
- The Bag of Visual Words (BoW) Algorithm extracts image features as words, presenting the histogram and vocabulary of an input image.

| Input Image | Output Image | Output Image | Output Image | Output Image | Output Image | 
| :---: | :---: | :---: | :---: | :---: | :---: | 
| ![scene](https://user-images.githubusercontent.com/76174639/199210343-28bbb7d8-99c0-45b1-97ec-25f64e8a4cfc.jpg) Scene Image | ![Scene Image with Detected Edges](https://user-images.githubusercontent.com/76174639/199210424-d3ca5a1b-1a2e-4c5e-8160-e547006a98d0.jpg)  Hough Line Transform with Edges | ![Scene Image with Detected Lines](https://user-images.githubusercontent.com/76174639/199210431-9e4b4887-a042-49e0-a7c8-9702e084d0fa.jpg)  Hough Line Transform with Lines | ![Scene Image with SIFT Features](https://user-images.githubusercontent.com/76174639/199210463-9e62c2bb-f134-49f6-a757-9a4cfd765289.jpg)  SIFT Features | ![Scene Image with Edges](https://user-images.githubusercontent.com/76174639/199210495-23461102-7a7f-46b9-990e-3a7f046d8dc2.jpg) Harris Corner | ![Histogram for Scene Image](https://user-images.githubusercontent.com/76174639/199211509-12912038-e6d8-42f1-bf3c-8c9dad2b009d.jpg) BoW Histogram |

---

## Software Requirements

The project was developed on macOS 10.13.6 environment. 

In order to run the project, it is required to install the following programs:
- Xcode 10.1
- OpenCV 3.4.0

---

## Installation

### Step 1: Install Xcode
First, it is required to download and install **Xcode** to run OpenCV projects for C++ on macOS environment. To install Xcode go to **App Store** -> **Search bar** -> **Type Xcode** -> **Click Install App** (see the following figure). Make sure that Xcode is stored in the Applications folder. The OpenCV project presented here was developed on **Xcode 10.1** and **macOS 10.13.6**.

![fig1](https://user-images.githubusercontent.com/76174639/197363657-32774932-cf69-407a-b30e-f058c19f1d61.png)

### Step 2: Download OpenCV Package
To download and install **OpenCV 3.4.0** package go to www.opencv.org and then go to **Library** -> **Releases** -> **Download OpenCV 3.4.0 Sources**. Open the zip file and place it on Desktop. In the opencv-3.4.0 folder, create a new folder and name it *build* (see the following figure).

![fig2](https://user-images.githubusercontent.com/76174639/197363690-788fce3a-d926-4c46-87b5-00680dc9ab35.png)

### Step 3: Install OpenCV
Go to www.cmake.org then click Download button. The binary distributions for MacOS are listed on this page (see the following figure). Since the platform is macOS 10.13, download and install **make-3.25.0-rc2-macos-universal.dmg**. Make sure that CMake is stored in the Applications folder.

![fig3](https://user-images.githubusercontent.com/76174639/197363696-e8b0fe57-9071-481e-abee-883fa1ca9bfe.png)

After installing the CMake software, open it and select the source and build folders as shown in the following figure. Then press **Configure** (please see the following figure).

![fig4](https://user-images.githubusercontent.com/76174639/197363701-1b20712b-bb4a-4c84-b821-d9477b289b8d.png)

Select **Unix Makefiles** and **use default native compilers**. Then press **Done**, and wait until the configuration is done (please see the following figure).

![fig5](https://user-images.githubusercontent.com/76174639/197363740-df8a5e2c-2088-4e64-87c8-b6facad92787.png)

After the configuration is done, check the build files out, and then press **Generate** in the CMake software (please see the following figure). 

![fig6](https://user-images.githubusercontent.com/76174639/197363705-6d8c75e5-53fc-4fc1-a0dd-26f731515349.png)

When the generation is done, close the CMake software (please see the following figure). 

![fig7](https://user-images.githubusercontent.com/76174639/197363706-f4f97304-9c75-4844-93d4-9a3aaeb92dbc.png)

Open the terminal, and type the following lines of codes.

``` 
$ cd Desktop/opencv-3.4.0/build
$ make
$ sudo make install
```

### Step 4: Link the OpenCV Libraries to Xcode

After installing OpenCV, open the Xcode project (the file you downloaded; main.xcodeproj). Go to **Build Settings**, and type **paths** in the search bar. Check if **Header Search Paths** and **Library Search Paths** are indicated as shown in the following figure. 

![fig8](https://user-images.githubusercontent.com/76174639/197363708-677a6925-52eb-44e3-99b1-441271f40751.png)

Make sure that the OpenCV libraries are linked to Xcode, and do not forget that the full path name of your libraries might be different than those in the downloaded Xcode project. Therefore, type **linking** in the search bar, and then clear contents in **Other Linker Flags**. Hold and drag the libraries from **Desktop/opencv-3.4.0/build/lib**, and then drop them to **Other Linker Flags** (please see the following figure).

![fig9](https://user-images.githubusercontent.com/76174639/197363714-ab300d14-0022-4c13-9fc9-ffeca5c789a1.png)

### Step 5: Change the Working Directory in Xcode

It is required to define a custom working directory to read and write images in Xcode. To do this, in Xcode, go to **Product** -> **Scheme** -> **Edit Scheme**. Then go to **Options**, and define 'your' **Working Directory**. It should contain the path name of the *main* folder you downloaded. In my case, it is /Users/BATURAY_OZGURUN/Desktop/main (please see the following figure).

![fig10](https://user-images.githubusercontent.com/76174639/197363718-feaa4af1-9e7c-4512-919a-1422d431dd3a.png)

Now the OpenCV project is ready to run.

#### Remarks: Setting Up OpenCV Extra Modules

This project may require an extra module, e.g., xfeatures2d. To build the extra module, go to https://github.com/opencv/opencv_contrib and download **opencv_contrib-3.4** folder. In this folder, find the module (e.g., xfeatures2d), copy and paste it into the **modules** folder of opencv-3.4.0. Open the CMake software, and then repeat Step 3 and Step 4.

---

## Citation

If you use this project in your research, please cite it as follows:

B. Ozgurun, Computer Vision Project -- Hough Line Transform - SIFT Features - Harris Corner - BoW Algorithms with OpenCV, (2022), GitHub repository, https://github.com/baturayozgurun/Computer_Vision_Project_Hough_Line_Transform-SIFT_Features-Harris_Corner-BoW_Algorithms_with_OpenCV

---

## License

This project is licensed under [MIT License](https://mit-license.org/).
