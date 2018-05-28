#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xclone_array>;
template xw::xmaterialize<xthree::xclone_array>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xclone_array>>;
template class xw::xgenerator<xthree::xclone_array>;
template xw::xgenerator<xthree::xclone_array>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xclone_array>>;