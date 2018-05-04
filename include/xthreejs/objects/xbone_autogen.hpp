#ifndef XTHREE_BONE_HPP
#define XTHREE_BONE_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"
#include "xwidgets/xprecompiled_macros.hpp"

#include "xtensor/xtensor.hpp"
#include "xtensor/xadapt.hpp"

#include "../base/xenums.hpp"
#include "../base/xthree_types.hpp"
#include "../core/xobject3d.hpp"

namespace xthree
{
    //
    // bone declaration
    //

    template<class D>
    class xbone : public xobject3d<D>
    {
    public:

        using base_type = xobject3d<D>;
        using derived_type = D;
        using buffer_type = xt::xtensor<float, 2>;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);



    protected:

        xbone();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using bone = xw::xmaterialize<xbone>;

    using bone_generator = xw::xgenerator<xbone>;

    //
    // bone implementation
    //


    template <class D>
    inline void xbone<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

    }

    template <class D>
    inline void xbone<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

    }

    template <class D>
    inline xbone<D>::xbone()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xbone<D>::set_defaults()
    {
        this->_model_name() = "BoneModel";
        this->_view_name() = "";
    }
}

/*********************
 * precompiled types *
 *********************/

#ifndef _WIN32
    extern template class xw::xmaterialize<xthree::xbone>;
    extern template class xw::xtransport<xw::xmaterialize<xthree::xbone>>;
    extern template class xw::xgenerator<xthree::xbone>;
    extern template class xw::xtransport<xw::xgenerator<xthree::xbone>>;
#endif

#endif