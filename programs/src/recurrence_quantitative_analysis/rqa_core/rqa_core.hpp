// Author:     Thomas Miethlinger B.Sc.
// Date:       16.10.2019
// Email:      t.miethlinger@protonmail.com
// University: Johannes Kepler University Linz, Austria

// STL
#include<vector>
#include<algorithm> // std::transform, std::min_element, std::max_element
#include<algorithm> // std::fill
#include<numeric> // std::accumulate

#pragma once

namespace rqa_core
{
    void calculate_recurrence_matrix(std::vector<double> &norm_distance_matrix, double eps, std::vector<double> &recurrence_matrix)
    {
        std::transform(norm_distance_matrix.begin(), norm_distance_matrix.end(), recurrence_matrix.begin(), [eps](double d){ return (d <= eps ? 1 : 0); });
    }

    void normalize_distance_matrix(std::vector<double> &distance_matrix, std::vector<double> &norm_distance_matrix)
    {
        double min = *std::min_element(distance_matrix.begin(), distance_matrix.end());
        double max = *std::max_element(distance_matrix.begin(), distance_matrix.end());
        std::transform(distance_matrix.begin(), distance_matrix.end(), norm_distance_matrix.begin(), [min, max](double d){ return ((d - min)/(max - min)); });
    }

    // Calculate the recurrence rate rr for a give recurrence matrix
    double recurrence_rate(std::vector<double> &recurrence_matrix)
    {
        double rr = 0;
        int n2 = recurrence_matrix.size();
        double sum = std::accumulate(recurrence_matrix.begin(), recurrence_matrix.end(), 0.0);
        rr = sum / (double)n2;
        return rr;
    }
};