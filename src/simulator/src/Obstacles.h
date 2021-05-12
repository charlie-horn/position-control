std::vector<std::vector<float>> get_obstacles() {
    std::vector<std::vector<float>> obstacles = {
            {1.09, 7.98, 2*0.12},
            {4.50, 7.59, 2*0.26},
            {8.28, 8.40, 2*0.18},
            {6.01, 3.68, 2*0.35},
            {8.63, 1.70, 2*0.18},
            {2.36, 3.71, 2*0.44},
            {3.07, 4.38, 2*0.22}
    };

    return obstacles;
};

/*float[7][3] get_obstacles(){
    return {{1.09, 7.98, 0.12},
        {4.50, 7.59, 0.26},
        {8.28, 8.40, 0.18},
        {6.01, 3.68, 0.35},
        {8.63, 1.70, 0.18},
        {2.36, 3.71, 0.44},
        {3.07, 4.38, 0.22}};
}*/

