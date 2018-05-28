#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xaudio_analyser>;
template xw::xmaterialize<xthree::xaudio_analyser>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xaudio_analyser>>;
template class xw::xgenerator<xthree::xaudio_analyser>;
template xw::xgenerator<xthree::xaudio_analyser>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xaudio_analyser>>;