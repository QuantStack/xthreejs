#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xcubic_interpolant>;
template xw::xmaterialize<xthree::xcubic_interpolant>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xcubic_interpolant>>;
template class xw::xgenerator<xthree::xcubic_interpolant>;
template xw::xgenerator<xthree::xcubic_interpolant>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xcubic_interpolant>>;