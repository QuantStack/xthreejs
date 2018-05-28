#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xskinned_mesh>;
template xw::xmaterialize<xthree::xskinned_mesh>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xskinned_mesh>>;
template class xw::xgenerator<xthree::xskinned_mesh>;
template xw::xgenerator<xthree::xskinned_mesh>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xskinned_mesh>>;