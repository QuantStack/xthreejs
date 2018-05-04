#ifndef XTHREE_CUBE_TEXTURE_HPP
#define XTHREE_CUBE_TEXTURE_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"
#include "xwidgets/xprecompiled_macros.hpp"

#include "xtensor/xtensor.hpp"
#include "xtensor/xadapt.hpp"

#include "../base/xenums.hpp"
#include "../base/xthree_types.hpp"
#include "xtexture_autogen.hpp"

namespace xthree
{
    //
    // cube_texture declaration
    //

    template<class D>
    class xcube_texture : public xtexture<D>
    {
    public:

        using base_type = xtexture<D>;
        using derived_type = D;
        using buffer_type = xt::xtensor<float, 2>;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);

        XPROPERTY(std::vector<double>, derived_type, images, std::vector<double>({}));


    protected:

        xcube_texture();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using cube_texture = xw::xmaterialize<xcube_texture>;

    using cube_texture_generator = xw::xgenerator<xcube_texture>;

    //
    // cube_texture implementation
    //


    template <class D>
    inline void xcube_texture<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

        xw::set_patch_from_property(images, state, buffers);
    }

    template <class D>
    inline void xcube_texture<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

        xw::set_property_from_patch(images, patch, buffers);
    }

    template <class D>
    inline xcube_texture<D>::xcube_texture()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xcube_texture<D>::set_defaults()
    {
        this->_model_name() = "CubeTextureModel";
        this->_view_name() = "";
    }
}

/*********************
 * precompiled types *
 *********************/

#ifndef _WIN32
    extern template class xw::xmaterialize<xthree::xcube_texture>;
    extern template class xw::xtransport<xw::xmaterialize<xthree::xcube_texture>>;
    extern template class xw::xgenerator<xthree::xcube_texture>;
    extern template class xw::xtransport<xw::xgenerator<xthree::xcube_texture>>;
#endif

#endif