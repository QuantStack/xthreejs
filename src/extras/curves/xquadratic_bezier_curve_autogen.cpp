#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xquadratic_bezier_curve>;
template xw::xmaterialize<xthree::xquadratic_bezier_curve>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xquadratic_bezier_curve>>;
template class xw::xgenerator<xthree::xquadratic_bezier_curve>;
template xw::xgenerator<xthree::xquadratic_bezier_curve>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xquadratic_bezier_curve>>;