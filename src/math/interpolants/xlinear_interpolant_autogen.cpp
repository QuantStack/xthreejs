#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xlinear_interpolant>;
template xw::xmaterialize<xthree::xlinear_interpolant>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xlinear_interpolant>>;
template class xw::xgenerator<xthree::xlinear_interpolant>;
template xw::xgenerator<xthree::xlinear_interpolant>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xlinear_interpolant>>;