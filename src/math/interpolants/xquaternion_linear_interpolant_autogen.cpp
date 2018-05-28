#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xquaternion_linear_interpolant>;
template xw::xmaterialize<xthree::xquaternion_linear_interpolant>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xquaternion_linear_interpolant>>;
template class xw::xgenerator<xthree::xquaternion_linear_interpolant>;
template xw::xgenerator<xthree::xquaternion_linear_interpolant>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xquaternion_linear_interpolant>>;