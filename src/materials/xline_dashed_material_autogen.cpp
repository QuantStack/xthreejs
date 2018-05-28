#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xline_dashed_material>;
template xw::xmaterialize<xthree::xline_dashed_material>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xline_dashed_material>>;
template class xw::xgenerator<xthree::xline_dashed_material>;
template xw::xgenerator<xthree::xline_dashed_material>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xline_dashed_material>>;