#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xcubic_bezier_curve>;
template xw::xmaterialize<xthree::xcubic_bezier_curve>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xcubic_bezier_curve>>;
template class xw::xgenerator<xthree::xcubic_bezier_curve>;
template xw::xgenerator<xthree::xcubic_bezier_curve>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xcubic_bezier_curve>>;