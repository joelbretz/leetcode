class Solution {
  public:
  void fill(vector<vector<int>>& image, int r, int c, int initColor, int finalColor) {

    image[r][c] = finalColor;

    if(((r+1) < image.size()) && image[r+1][c] == initColor)
      fill(image,r+1,c,initColor,finalColor);
    if(((r-1) >= 0) && image[r-1][c] == initColor)
      fill(image,r-1,c,initColor,finalColor);
    if(((c+1) < image[0].size()) && image[r][c+1]==initColor)
      fill(image,r,c+1,initColor,finalColor);
    if(((c-1) >= 0) && image[r][c-1] == initColor)
      fill(image,r,c-1,initColor,finalColor);

  }

  vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

    auto initialColor = image[sr][sc];
    if(initialColor != color)
      fill(image,sr,sc,initialColor,color);
    return image;
  }
};
