#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xspline_curve>;
template xw::xmaterialize<xthree::xspline_curve>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xspline_curve>>;
template class xw::xgenerator<xthree::xspline_curve>;
template xw::xgenerator<xthree::xspline_curve>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xspline_curve>>;