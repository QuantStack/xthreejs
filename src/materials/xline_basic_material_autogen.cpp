#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xline_basic_material>;
template xw::xmaterialize<xthree::xline_basic_material>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xline_basic_material>>;
template class xw::xgenerator<xthree::xline_basic_material>;
template xw::xgenerator<xthree::xline_basic_material>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xline_basic_material>>;