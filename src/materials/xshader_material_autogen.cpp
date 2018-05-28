#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xshader_material>;
template xw::xmaterialize<xthree::xshader_material>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xshader_material>>;
template class xw::xgenerator<xthree::xshader_material>;
template xw::xgenerator<xthree::xshader_material>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xshader_material>>;